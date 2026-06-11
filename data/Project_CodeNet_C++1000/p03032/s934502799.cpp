#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;
template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
// long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define rep(i, a, n) for (long long i = a; i < (n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
long long mod = 1000000007;
long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t % 13;
    } else {
        return modpow(m, n - 1) * m % 13;
    }
}
long long power(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = pow(m, n / 2);
        return t * t;
    } else {
        return pow(m, n - 1) * m;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

const ll INF = 1LL << 60;

string change_binary(long long a) {
    string ret;
    for (int i = 31; i >= 0; i--) {
        ret += (a >> i & 1) + '0';
    }
    return ret;
}

ll nCkmod(ll n, ll k) {
    ll denomi = 1;
    for (int i = n; i > n - k; i--) {
        denomi *= i;
        denomi %= mod;
    }
    ll numera = 1;
    REP(i, k) {
        numera *= (i + 1);
        numera %= mod;
    }
    return moddiv(denomi, numera);
}
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    REP(i, n) { cin >> v[i]; }
    ll ans = 0;
    REP(i, n + 1) {
        REP(j, n + 1) {
            vector<ll> neg;
            ll cur = 0;
            if (i + j <= min(k, n)) {
                REP(l, i) {
                    if (v[l] < 0) {
                        neg.push_back(v[l]);
                    }
                    cur += v[l];
                }
                REP(l, j) {
                    if (v[n - 1 - l] < 0) {
                        neg.push_back(v[n - 1 - l]);
                    }
                    cur += v[n - 1 - l];
                }
                sort(neg.begin(), neg.end());
                REP(l, min(k - i - j, (ll)neg.size())) { cur -= neg[l]; }
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << endl;
}