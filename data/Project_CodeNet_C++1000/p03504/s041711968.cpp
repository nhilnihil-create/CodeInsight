#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

using P = pair<int, int>;
int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<P>> st(C);
    vector<int> T(1e5 + 2);
    for (int i = 0; i < N; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        st[c].push_back(P(s, t));
    }
    for (int i = 0; i < C; i++) {
        sort(ALL(st[i]));
        for (int j = 0; j < (int)st[i].size(); j++) {
            if (j == 0 || st[i][j - 1].second != st[i][j].first) {
                T[st[i][j].first]++;
                T[st[i][j].second + 1]--;
            } else {
                T[st[i][j - 1].second + 1]++;
                T[st[i][j].second + 1]--;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 100001; i++) {
        T[i + 1] += T[i];
        chmax(ans, T[i + 1]);
    }
    cout << ans << endl;
}
