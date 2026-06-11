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
        return t * t % mod;
    } else {
        return modpow(m, n - 1) * m % mod;
    }
}
long long power(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

const ll INF = 1LL << 60;

void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
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
vector<vector<ll>> graph;
vector<ll> as;
map<P, ll> number;
ll rmemo[101][300001];
ll memo[101][300001];
int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> as(n);
    memo[n][k] = 1;
    REP(i, n) { cin >> as[i]; }
    for (int i = n - 1; i >= 0; i--) {
        REP(j, 200001) { rmemo[i + 1][j + 1] = (memo[i + 1][j] + rmemo[i + 1][j]) % mod; }
        REP(j, k + 1) {
            memo[i][j] = (rmemo[i + 1][j + as[i] + 1] - rmemo[i + 1][j]) % mod;
            // cout << memo[i][j] << endl;
        }
    }
    cout << (memo[0][0] + mod) % mod << endl;
}