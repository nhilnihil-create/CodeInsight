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
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<ll> dp((1 << n), -LLINF);
    dp[0] = 0;
    for(int S = 0; S < (1 << n); S++) {
        ll tmp = 0;
        for(int i = 0; i < n; i++) {
            if(S & (1 << i)) {
                for(int j = i + 1; j < n; j++) {
                    if(S & (1 << j)) {
                        tmp += a[i][j];
                    }
                }
            }
        }
        dp[S] = tmp;
        for(int T = (S - 1) & S; T > 0; T = (T - 1) & S) {
            chmax(dp[S], dp[T] + dp[S ^ T]);
        }
    }
    print(dp[(1 << n) - 1]);
}