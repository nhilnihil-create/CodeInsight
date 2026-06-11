#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll H,W,D;
    cin >> H >> W >> D;
    vector<vector<ll>> A(H,vector<ll>(W));
    map<ll, Pll> mp;
    rep(i,H)rep(j,W){
        cin >> A[i][j];
        mp[A[i][j]] = Pll(i,j);
    }
    ll Q;
    cin >> Q;
    vector<ll> L(Q),R(Q),S(H*W+2);
    for(ll i=D;i<=H*W;i++){
        S[i+1] = S[i+1-D] +  abs(mp[i+1].first - mp[i+1-D].first) + abs(mp[i+1].second - mp[i+1-D].second);
    }
    rep(i,Q) cin >> L[i] >> R[i];
    rep(i,Q){
        cout << S[R[i]] - S[L[i]] << endl;
    }
}
