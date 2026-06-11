#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long MOD = 1e9 + 7;

int main() {
    map<ll, ll> c;
    ll N, M, A, B;
    cin >> N >> M;
    rep(i, N) {
        cin >> A;
        c[A]++;
    }
    rep(i, M) {
        cin >> B >> A;
        c[A] += B;
    }
    ll sum = 0;
    int ch = 0;
    auto it = c.rbegin();
    for(; it != c.rend(); it++) {
        if(ch + it->second <= N) {
            sum += it->first * it->second;
            ch += it->second;
        } else {
            sum += it->first * (N - ch);
            break;
        }
    }
    cout << sum << endl;
}