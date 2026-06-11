#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    ll L = lcm(N, M);
    ll ln = L/N, lm = L/M;

    bool ok = true;

    rep(i, min(N/lm, M/ln)) {
        if (S[lm*i] != T[ln*i]) ok = false;
    }

    if (ok) cout << L << endl;
    else cout << -1 << endl;

    return 0;
}