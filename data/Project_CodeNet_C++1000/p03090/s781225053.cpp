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
    int N;
    cin >> N;
    if (N == 3) {
        cout << 2 << endl;
        cout << "1 3\n2 3" << endl;
        return 0;
    } else if (N == 4) {
        cout << 4 << endl;
        cout << "1 2\n1 3\n4 2\n4 3\n";
        return 0;
    }
    using P = pair<int, int>;
    vector<P> ans;
    if (N % 2 == 1) {
        int K = N - 1;
        vector<vector<int>> a(K / 2 + 2);
        for (int i = 0; i < K / 2; i++) {
            a[i + 1].push_back(i + 1);
            a[i + 1].push_back(K - i);
        }
        a[0].push_back(N);
        a[K / 2 + 1].push_back(N);
        for (int i = 0; i <= K / 2; i++) {
            for (auto v : a[i]) {
                for (auto u : a[i + 1]) {
                    ans.push_back({v, u});
                }
            }
        }
    } else {
        int K = N;
        vector<vector<int>> a(K / 2 + 1);
        for (int i = 0; i < K / 2; i++) {
            a[i + 1].push_back(i + 1);
            a[i + 1].push_back(K - i);
            if (i == (K / 2 - 1)) {
                a[0].push_back(i + 1);
                a[0].push_back(K - i);
            }
        }
        for (int i = 0; i < K / 2; i++) {
            for (auto v : a[i]) {
                for (auto u : a[i + 1]) {
                    ans.push_back({v, u});
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << ' ' << p.second << "\n";
    }
}
