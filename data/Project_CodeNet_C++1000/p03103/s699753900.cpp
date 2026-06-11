/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll> > x;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        x.push_back(make_pair(a,b));
    }
    sort(x.begin(), x.end());
    ll sum=0, cnt=0;
    for(ll i=0;i<x.size();i++){
        ll fi = x[i].first, se=x[i].second;
        if(sum==m)  break;
        if(sum+se<=m){
            sum += se;
            cnt += ((ll)fi*se); 
           // cout<<"A: "<<sum<<" "<<cnt<<endl;
        }
        else{
            //cout<<"Left: "<<(m-sum)<<endl;
            //cout<<"Price: "<<fi<<endl;
            cnt += (fi*(m-sum));
            sum += (m-sum);
            //cout<<"B: "<<sum<<" "<<cnt<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

