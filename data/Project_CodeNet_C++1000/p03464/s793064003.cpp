#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const long double pi = acos(-1.0);
typedef complex<ld> cd;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;
    vector<ll> a(k);
    rep(i,k) cin >> a[i];

    ll min_n = 2, max_n = 2;
    per(i, k) {
        ll min_num = ((min_n + a[i] - 1) / a[i]) * a[i];
        ll max_num = (max_n / a[i]) * a[i] + a[i] - 1;
        if(min_num > max_n || max_num < min_n){
            cout << -1 << endl;
            return 0;
        }
        min_n = min_num;
        max_n = max_num;
    }
    cout << min_n << " " << max_n << endl;
}
