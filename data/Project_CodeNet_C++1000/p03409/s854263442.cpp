#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
using ipair = pair<int,int>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
const int MOD=1000000007;
int main(){
    int n;cin>>n;
    priority_queue<ipair,vector<ipair>,greater<ipair>>b,cp;
    vector<ipair> r;
    ll x,y;
    rep(i,n){
        cin>>x>>y;
        r.push_back(make_pair(x,y));
    }
    rep(i,n){
        cin>>x>>y;
        b.push(make_pair(x,y));
    }
    sort(r.begin(),r.end());
    int cnt = 0,mx = -1,mxx=0;
    rep(i,n){
        int ok = 0;
        ipair ba = b.top();b.pop();
        mx = -1;mxx=0;
        for (int i = 0; i < r.size(); i++)
        {        
            if(ba.first<r[i].first)break;
            if(ba.second>r[i].second&&mx<r[i].second){
                //cout<<"r"<<r[i].second<<endl;
                ok = 1;
                mx =r[i].second;
                mxx = i;
            }
        }      
        if(ok){cnt++;
        r.erase(r.begin()+mxx);}
    }
    cout<<cnt<<endl;
    return 0;
}