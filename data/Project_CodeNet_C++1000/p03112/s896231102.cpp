#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int A, B, Q; cin >> A >> B >> Q;
    vector<ll> S(A), T(B);
    REP(i, 0, A) cin >> S[i];
    REP(i, 0, B) cin >> T[i];

    REP(i, 0, Q) {
        ll x; cin >> x;

        int rs = lower_bound(ALL(S), x) - S.begin();
        int ls = rs - 1;
        int rt = lower_bound(ALL(T), x) - T.begin();
        int lt = rt - 1;

        ll dist = 1LL << 60;
        if (rs < A && rt < B) dist = min(dist, max(S[rs], T[rt]) - x);
        if (ls >= 0 && lt >= 0) dist = min(dist, x - min(S[ls], T[lt]));
        if (rs < A && lt >= 0) dist = min(dist, S[rs] - T[lt] + min(abs(S[rs] - x), abs(T[lt] - x)));
        if (rt < B && ls >= 0) dist = min(dist, T[rt] - S[ls] + min(abs(S[ls] - x), abs(T[rt] - x)));
        cout << dist << endl;
    }
    return 0;
}