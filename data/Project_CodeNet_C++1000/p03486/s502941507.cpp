#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    string s,t;
    cin>>s>>t;
    sort(all(s));
    
    sort(all(t));
    reverse(all(t));

    vector<string> v;
    v.push_back(s);
    v.push_back(t);
    sort(all(v));

    //cout<<v[0]<<" "<<v[1]<<endl;

    if(s==t){
        cout<<"No"<<endl;
        return 0;
    }

    if(v[0]==s) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}


