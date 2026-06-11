#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
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

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int K;
    cin >> K;

    set<string> str_set;
    REP(i, s.size()) {
        FOR(j, 1, 5 + 1) {
            if (i + j - 1 < s.size()) {
                str_set.insert(s.substr(i, j));
            }
        }
    }
    priority_queue<string, vector<string>, greater<string>> q;
    for (string str : str_set) {
        q.push(str);
    }

    string ans;
    LOOP(K) {
        ans = q.top();
        q.pop();
    }

    cout << ans << endl;
    return 0;
}
