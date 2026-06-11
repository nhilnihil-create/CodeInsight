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
    string S;
    cin >> S;
    int N = S.size();

    vector<int> check(26);
    vector<string> can;
    for (int i = 0; i < N; i++) {
        check[S[i] - 'a'] = 1;
        string tmp = S.substr(0, i);
        int m = -1;
        for (int j = S[i] - 'a'; j < 26; j++) {
            if (check[j] == 0) {
                tmp.push_back((char)('a' + j));
                m = 1;
                break;
            }
        }
        if (m != -1) can.push_back(tmp);
    }

    if (N == 26) {
        if (can.size() > 0) {
            sort(can.begin(), can.end());
            cout << can[0] << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        if (check[i] == 0) {
            cout << S << char(i + 'a') << endl;
            return 0;
        }
    }
}
