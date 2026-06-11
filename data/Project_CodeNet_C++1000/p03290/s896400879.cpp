#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}
typedef long long ll;
typedef pair<ll, ll> P;
map<long long, long long> cnt;
void primeFactors(long long n) {
    while (n % 2 == 0) {
        cnt[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cnt[i]++;
            n = n / i;
        }
    }
    if (n > 2) {
        cnt[n]++;
    }
}
bool bitcheck(int x, int y) { return (x >> y) & 1; }
signed main() {
    ll d, g;
    cin >> d >> g;
    vector<ll> p(d);
    vector<ll> c(d);
    REP(i, d) {
        cin >> p[i];
        cin >> c[i];
    }
    ll mnproblems = 1000000;
    REP(i, 1 << d) {
        ll sum = 0;
        ll problems = 0;
        REP(j, d) {
            if (bitcheck(i, j)) {
                sum += p[j] * (j + 1) * 100 + c[j];
                problems += p[j];
            }
        }
        if (sum >= g) {
            mnproblems = min(mnproblems, problems);
        }
        for (int j = d - 1; j >= 0; j--) {
            if (!bitcheck(i, j)) {
                if (sum < g) {
                    problems += (((g - sum + (j + 1) * 100) - 1) / ((j + 1) * 100));
                }
                sum += (p[j] - 1) * (j + 1) * 100;
                if (sum >= g) {
                    mnproblems = min(mnproblems, problems);
                }
            }
        }
    }
    cout << mnproblems << endl;
}