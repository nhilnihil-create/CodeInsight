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
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b.at(i);
    }
    vector<int> ans;

    for (int i = 0; i < N; i++) {
        for (int j = (int)b.size() - 1; j >= 0; j--) {
            if (b[j] == j + 1) {
                b.erase(b.begin() + j);
                ans.push_back(j + 1);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if ((int)b.size() > 0) {
        cout << -1 << endl;
    } else {
        for (auto i : ans) {
            cout << i << "\n";
        }
    }
}
