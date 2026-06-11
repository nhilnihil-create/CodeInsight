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
    int n; cin >> n;
    vector<pair<int, int>> red(n), blue(n);
    rep(i, n) cin >> red[i].first >> red[i].second;
    rep(i, n) cin >> blue[i].first >> blue[i].second;

    sort(all(red), [](pair<int, int> a, pair<int, int> b) { // y座標降順
        return a.second > b.second;
    });
    sort(all(blue)); // x座標昇順

    int ans = 0;
    rep(i, n) { // blueをx座標昇順に見ていく
        int s = red.size();
        rep(j, s) { // redをy座標降順に見ていく
            if(red[j].first < blue[i].first && red[j].second < blue[i].second) { // ペアが見つかったら
                ans++;
                red.erase(red.begin() + j); // ペアになったredを削除。blueは元々1回ずつしか見ない
                break;
            }
        }
    }
    cout << ans << endl;
}
