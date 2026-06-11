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
const int INF = 2100100100;
// const int MOD = 1e9 + 7;

int main() {
    int N, C;
    cin >> N >> C;
    auto D = make_vec<int>(C, C);
    auto c = make_vec<int>(N, N);
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    auto num = make_vec<int>(3, C);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a = (i + j + 2) % 3;
            num[a][c[i][j]]++;
        }
    }

    long long ans = 1e18;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < C; k++) {
                if (i == j || j == k || k == i) continue;
                long long sum = 0;
                for (int l = 0; l < C; l++) {
                    sum += D[l][i] * num[0][l];
                }
                for (int l = 0; l < C; l++) {
                    sum += D[l][j] * num[1][l];
                }
                for (int l = 0; l < C; l++) {
                    sum += D[l][k] * num[2][l];
                }
                chmin(ans, sum);
            }
        }
    }
    cout << ans << endl;
}
