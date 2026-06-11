#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    ll r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    int N, M; string S, T; cin >> N >> M >> S >> T;
    
    ll g = gcd(N, M);
    ll l = N / g * M;

    bool ok = true;
    N /= g; M /= g;
    REP(i, 0, g) {
        if (S[N * i] != T[M * i]) ok = false;
    }

    if (ok) cout << l << endl;
    else cout << -1 << endl;

    return 0;
}