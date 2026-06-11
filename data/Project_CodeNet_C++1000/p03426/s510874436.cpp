#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll H,W,D,Q;
    cin >> H >> W >> D;
    vector<vector<ll>> A(H,vector<ll>(W));
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    cin >> Q;
    vector<ll> L(Q), R(Q);
    rep(i,Q){
        cin >> L[i] >> R[i];
    }
    map<ll,Pll> mp;
    rep(i,H){
        rep(j,W){
            mp[A[i][j]] = Pll(i,j);
        }
    }
    vector<ll> S(H*W+1);
    rep(i,H*W+1){
       if(i-D>=0){
           S[i] = S[i-D] + abs(mp[i].fi - mp[i-D].fi) + abs(mp[i].se - mp[i-D].se);
       } 
    }
    rep(i,Q){
        cout << S[R[i]] - S[L[i]] << endl;
    }
}
