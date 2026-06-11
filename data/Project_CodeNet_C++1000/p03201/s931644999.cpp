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
const int MOD = 1e9 + 7;

ll N, M, K, Q;
string S;

int main() {
    cin >> N;
    vector<ll> a(N);
    map<ll, int> m;
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        m[a[i]]++;
    }

    sort(ALL(a), greater<ll>());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (m[a[i]] == 0) continue;
        for (int t = 0; t < 32; t++) {
            ll two = 1LL << (ll)t;
            if (two - a[i] > 0) {
                if (two - a[i] != a[i]) {
                    if (m[two - a[i]] >= 1) {
                        ans += 1;
                        m[a[i]]--;
                        m[two - a[i]]--;
                        break;
                    }
                } else {
                    if (m[two - a[i]] >= 2) {
                        ans += 1;
                        m[a[i]]--;
                        m[two - a[i]]--;
                        break;
                    }
                }
            }
        }
        //debug(ans);
    }
    cout << ans << endl;
}
