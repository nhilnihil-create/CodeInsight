#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int N;
    string s;
    cin >> N >> s;

    map<pair<string, string>, int> mp;
    for (int bits=0; bits<(1<<N); ++bits) {
        string s1 = "", s2 = "";
        for (int i=0; i<N; ++i) {
            if (bits & (1<<i)) s1 += s[i];
            else s2 = s[i] + s2;
        }
        ++mp[make_pair(s1, s2)];
    }
    ll res = 0;
    for (int bits=0; bits<(1<<N); ++bits) {
        string s1 = "", s2 = "";
        for (int i=0; i<N; ++i) {
            if (bits & (1<<i)) s1 += s[i+N];
            else s2 = s[i+N] + s2;
        }
        res += mp[make_pair(s2, s1)];
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
