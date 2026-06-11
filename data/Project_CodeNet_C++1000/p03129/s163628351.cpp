#include <bits/stdc++.h>
using namespace std;

#define int long long
#define For(i, a, b) for (int i = (a); i <= static_cast<int>(b); i++)
#define Forr(i, a, b) for (int i = (a); i >= static_cast<int>(b); i--)
#define rep(i, n) For(i, 0, n - 1)
#define repall(i, arr) for (auto& i : (arr))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << '\n'

template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqr = priority_queue<T, vector<T>, greater<T>>;
const int INF = INT_MAX / 2;
constexpr int MOD = 1e9 + 7;

template <typename T1, typename T2>
ostream& operator<<(ostream& stream, const pair<T1, T2>& p) {
    return stream << p.first << " " << p.second;
}
template <typename T>
void print(const vector<vector<T>> matrix) {
    repall (vec, matrix)
        print(vec);
}
template <typename T>
void print(const vector<T> vec) {
    unsigned int len = vec.size();
    rep (i, len - 1)
        cout << vec[i] << ' ';
    cout << vec[len - 1] << '\n';
}
template <typename Arg>
void print(const Arg arg) {
    cout << arg << '\n';
}
template <typename Head, typename... Args>
void print(const Head head, const Args... args) {
    cout << head << " ";
    print(args...);
}
template <typename T>
T sum_(vector<T> vec, T init = 0) {
    return std::accumulate(all(vec), T(init));
}
// -------------------------------------------------------------------

using P = pair<int, int>;

signed main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    print((n + 1) / 2 >= k ? "YES" : "NO");

    return 0;
}
