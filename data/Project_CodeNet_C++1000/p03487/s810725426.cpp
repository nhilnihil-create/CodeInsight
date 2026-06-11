#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    map<ll,ll> mp;
    rep(i,n){
        ll a;cin>>a;
        mp[a]++;
    }
    ll now=0;
    for(auto& p:mp){
        ll it=p.first,m=p.second;
        //cout<<it<<" "<<m<<endl;
        if(it>m)continue;
        now+=it;
    }
    ll res=n-now;
    cout<<res<<endl;
}