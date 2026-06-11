#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(m);
    rep(i, m) cin >> v[i].first >> v[i].second;
    sort(all(v), [](pair<int, int> x, pair<int, int> y){ // secondでソート。pairを(b, a)にすれば普通のソートでok
        return x.second < y.second;
    });
    int ans = 0;
    int now = 0;
    rep(i, m) {
        if(now <= v[i].first) {
            ans++;
            now = v[i].second;
        }
    }
    cout << ans << endl;
}
