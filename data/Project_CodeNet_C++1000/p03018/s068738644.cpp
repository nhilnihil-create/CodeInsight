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

int main() {
    string s;
    cin >> s;
    vector<string> S;
    string tmp = "";
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'A') {
            tmp.push_back('A');
        } else if (s[i] == 'B') {
            if (i + 1 < (int)s.size() && s[i + 1] == 'C') {
                tmp.push_back('B');
                i++;
            } else {
                S.push_back(tmp);
                tmp = "";
            }
        } else {
            S.push_back(tmp);
            tmp = "";
        }
    }
    S.push_back(tmp);

    ll ans = 0;
    for (auto str : S) {
        ll N = str.size();
        ll na = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (str[i] == 'A') {
                ans += (N - 1 - i) - na;
                na++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
