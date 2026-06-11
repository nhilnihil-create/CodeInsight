#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n), sorted_x, sorted_y;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        sorted_x.emplace_back(x[i]);
        sorted_y.emplace_back(y[i]);
    }
    sort(ALL(sorted_x));
    sort(ALL(sorted_y));
    ll ans = __LONG_LONG_MAX__;
    for(int a = 0; a < n; a++) {
        for(int b = a + 1; b < n; b++) {
            for(int c = 0; c < n; c++) {
                for(int d = c + 1; d < n; d++) {
                    int cnt = 0;
                    ll lx = sorted_x[a];
                    ll ly = sorted_y[c];
                    ll rx = sorted_x[b];
                    ll ry = sorted_y[d];
                    for(int i = 0; i < n; i++) {
                        if(lx <= x[i] && x[i] <= rx && ly <= y[i] &&
                           y[i] <= ry) {
                            cnt++;
                        }
                    }
                    if(cnt >= k) {
                        chmin(ans, (rx - lx) * (ry - ly));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}