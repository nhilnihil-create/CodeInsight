#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<bitset<10>> f(n);
    rep(i,n){
        rep(j,10){
            int x;cin>>x;
            f[i].set(j,x);
        }
    }
    vector<vector<ll>> p(n,vector<ll>(11));
    rep(i,n)rep(j,11)cin>>p[i][j];
    ll res=-1e+18;
    for(int tmp=1;tmp<(1<<10);tmp++){
        bitset<10> s(tmp);
        ll now=0;
        rep(i,n){
            int k=0;
            rep(j,10)k+=s[j]&f[i][j];
            now+=p[i][k];
        }
        chmax(res,now);
    }
    cout<<res<<endl;
}