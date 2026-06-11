#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll n,m; cin>>n>>m;
    vector<ll> x(n), y(n), z(n);
    rep(i,n) cin>>x[i]>>y[i]>>z[i];

    ll res=0;
    rep(i,8){
        ll tmp=0;
        vector<bool> ifinc(3);
        rep(j,3){
            if(i>>j & 1) ifinc[j]=true;
            else ifinc[j]=false;
        }

        vector<ll> w(n, 0);

        if(ifinc[0]){
            rep(j,n) w[j]+=(-1)*x[j];
        }else{
            rep(j,n) w[j]+=x[j];
        }

        if(ifinc[1]){
            rep(j,n) w[j]+=(-1)*y[j];
        }else{
            rep(j,n) w[j]+=y[j];
        }

        if(ifinc[2]){
            rep(j,n) w[j]+=(-1)*z[j];
        }else{
            rep(j,n) w[j]+=z[j];
        }

        sort(w.begin(), w.end(), greater<ll>());
        rep(j,m) tmp+=w[j];

        chmax(res, tmp);
        
    }
    cout<<res<<endl;
    return 0;
}