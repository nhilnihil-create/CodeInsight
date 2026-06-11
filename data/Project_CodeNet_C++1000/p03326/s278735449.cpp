#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    vector<ll> x(n),y(n),z(n);
    rep(i,n) cin>>x[i]>>y[i]>>z[i];
    ll res= (-1e+18);
    rep(i,8){
        priority_queue<ll> que;
        rep(j,n){
            int b=i;
            ll now=0;
            if(b%2==1)now-=x[j];
            else now+=x[j];
            b/=2;
            if(b%2==1)now-=y[j];
            else now+=y[j];
            b/=2;
            if(b%2==1)now-=z[j];
            else now+=z[j];
            que.push(now);
        }
        ll buf=0;
        rep(j,m){
            buf+=que.top();que.pop();
        }
        //cout<<buf<<endl;
        chmax(res,buf);
    }
    cout<<res<<endl;
}