#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll n,c; cin>>n>>c;
    vector<ll> col1(c+1), col2(c+1), col3(c+1);
    vector<vector<ll>> d(c, vector<ll>(c));
    rep(i,c) rep(j,c) cin>>d[i][j];
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            ll d; cin>>d;
            if((i+j)%3==1) col1[d]++;
            if((i+j)%3==2) col2[d]++;
            if((i+j)%3==0) col3[d]++;
        }
    }
    ll res=1e10;
    for(ll x=1; x<=c; x++){
        for(ll y=1; y<=c; y++){
            for(ll z=1; z<=c; z++){
                if(x==y || x==z || y==z) continue;
                ll tmp=0;
                rep(i,c) tmp += col1[i+1] * d[i][x-1];
                rep(i,c) tmp += col2[i+1] * d[i][y-1];
                rep(i,c) tmp += col3[i+1] * d[i][z-1];
                chmin(res, tmp);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}