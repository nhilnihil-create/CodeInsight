#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    int N, M; string S, T; cin >> N >> M >> S >> T;
    ll L = lcm(N, M);

    map<ll, char> m;
    REP(i, 0, N) m[L / N * i + 1] = S[i];
    REP(i, 0, M) {
        if (m[L / M * i + 1] != 0 && m[L / M * i + 1] != T[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << L << endl;
    return 0;
}