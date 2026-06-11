#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(3));
    rep(i,n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    ll ans = 0;
    rep(S,(1<<3)){
        vector<ll> v;
        rep(i,n){
            ll b = 0;
            rep(j,3){
                if(S>>j & 1) b += a[i][j];
                else b -= a[i][j];
            }
            v.push_back(b);
        }
        sort(v.rbegin(), v.rend());
        ll cmp = 0;
        rep(i,m) cmp += v[i];
        chmax(ans, cmp);
    }
    cout << ans << endl;
	return 0;
}