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
    rep(i, m) {
        int a, b; cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(all(v), [](pair<int, int> x, pair<int, int> y){
        if(x.second != y.second) return x.second < y.second;
        else return x.first < y.first;
    });
    int ans = 1;
    int now = v[0].second;
    Rep(i, 1, m) {
        if(now <= v[i].first) {
            ans++;
            now = v[i].second;
        }
    }
    cout << ans << endl;
}
