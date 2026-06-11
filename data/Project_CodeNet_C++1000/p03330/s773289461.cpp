#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,C;cin>>n>>C;
    vector<vector<ll>> d(C,vector<ll>(C));
    rep(i,C)rep(j,C)cin>>d[i][j];
    vector<vector<ll>> v(3,vector<ll>(31,0));
    rep(i,n)rep(j,n){
        ll x;cin>>x;
        v[(i+j)%3][x-1]++;
    }
    ll res=1e10;
    rep(i,C)rep(j,C)rep(k,C){
        if(i==j||j==k||k==i)continue;
        ll buf=0;
        rep(l,C)buf+=d[l][i]*v[0][l];
        rep(l,C)buf+=d[l][j]*v[1][l];
        rep(l,C)buf+=d[l][k]*v[2][l];
        chmin(res,buf);
    }
    cout<<res<<endl;
}