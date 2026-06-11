#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

P c[90005];
ll dp[90005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        c[a[i][j]].first = i;
        c[a[i][j]].second = j;
    }
    for(int i = 1; i <= h*w; ++i){
        if(i+d <= h*w) dp[i+d] = dp[i] + abs(c[i].first - c[i+d].first) + abs(c[i].second - c[i+d].second);
    }
    int q;
    cin >> q;
    rep(i,q){
        int l, r;
        cin >> l >> r;
        ll ans = dp[r] - dp[l];
        cout << ans << endl;
    }
    return 0;
}
