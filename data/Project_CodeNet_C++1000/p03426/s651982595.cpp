#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
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
    map<ll,Pll> mp;
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
            mp[A[i][j]] = Pll(i,j);
        }
    }
    cin >> Q;
    vector<ll> dp(H*W+10);
    rep(i,H*W){
        if(i<D)continue;
        dp[i+1] = dp[i+1-D] + abs(mp[i+1].first - mp[i+1-D].first) + abs(mp[i+1].second - mp[i+1-D].second);
    }
    ll L,R;
    vector<ll> v;
    rep(i,Q){
        cin >> L >> R;
        v.push_back(dp[R]-dp[L]);
    }
    rep(i,Q){
        cout << v[i] << endl;
    }
}