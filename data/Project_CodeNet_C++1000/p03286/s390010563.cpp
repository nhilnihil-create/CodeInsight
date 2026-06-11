#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    if(N == 0) {
        cout << 0 << endl;
        return 0;
    }
    string ans = "";
    while(abs(N) > 0) {
        int d = abs(N) & 1 ? 1 : 0;
        N -= d;
        N /= -2;
        ans = (d ? "1" : "0") + ans;
    }
    cout << ans << endl;
    return 0;
}