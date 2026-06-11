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
    int N, H;
    cin >> N >> H;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ma = a[N - 1];
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (b[i] > ma) {
            cnt++;
            H -= b[i];
        } else {
            break;
        }
        if (H <= 0) {
            cout << cnt << endl;
            return 0;
        }
    }
    cout << cnt + (H + ma - 1) / ma << endl;
    return 0;
}
