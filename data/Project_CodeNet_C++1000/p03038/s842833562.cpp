#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    priority_queue<pair<ll,ll>> que;
    rep(i,n){
        ll a;cin>>a;
        que.push({a,1});
    }
    rep(i,m){
        ll b,c;cin>>b>>c;
        que.push({c,b});
    }
    ll tmp=0,res=0;
    while(tmp<n){
        ll x=que.top().first,y=que.top().second;que.pop();
        ll buf=min(y,n-tmp);
        tmp+=buf;
        res+=x*buf;
    }
    cout<<res<<endl;
}
