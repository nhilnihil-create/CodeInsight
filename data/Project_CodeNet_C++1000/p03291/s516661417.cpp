#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
string s;
ll acnt[N];
ll ccnt[N];
ll qcnt[N];
ll ans, a, c, q;
ll p[N];

void init() {
    p[0] = 1;
    for (int i = 1; i < N; ++i) {
        p[i] = p[i - 1] * 3 % mod;
    }
}

inline static ll pp(int x) {
    if (x <= 0) return 1;
    return p[x];
}

int main() {
    init();
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        char C = s[i];
        if (C == 'A') {
            ++a;
        } else if (C == 'C') {
            ++c;
        } else if (C == '?') {
            ++q;
        }
        acnt[i] = a;
        ccnt[i] = c;
        qcnt[i] = q;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B' || s[i] == '?') {
            ll left = acnt[i];
            ll lq = qcnt[i] - (s[i] == '?' ? 1 : 0);
            ll right = c - ccnt[i];
            ll rq = q - qcnt[i];
            ans = (ans + left * right % mod * pp(lq + rq) % mod) % mod;
            ans = (ans + left * rq % mod * pp(lq + rq - 1) % mod) % mod;
            ans = (ans + right * lq % mod * pp(lq + rq - 1) % mod) % mod;
            ans = (ans + lq * rq % mod * pp(lq + rq  - 2) % mod) % mod;
        }
    }

    cout << ans << endl;
    return 0;
}
