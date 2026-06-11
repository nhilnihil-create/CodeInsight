#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
const long long INFLL = 1LL << 60;
const int INFINT = 1 << 30;
const long long MOD = 1e9 + 7;

template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10, 0));
    vector<vector<int>> P(N, vector<int>(11, 0));
    rep(i, N) rep(j, 10) cin >> F[i][j];
    rep(i, N) rep(j, 11) cin >> P[i][j];

    int x = INT_MIN;
    rep(k, 1, 1024) {
        int prof = 0;
        rep(i, N) {
            int m = 0;
            rep(j, 10) if((k >> j & 1) && F[i][j]) m++;
            prof += P[i][m];
        }
        chmax(x, prof);
    }
    cout << x << endl;
}