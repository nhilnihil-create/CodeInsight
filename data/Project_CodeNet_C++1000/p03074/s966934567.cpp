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
ll n;
ll memo[3001][3001];
ll func(ll first, ll length) {
    if (length == 0) {
        return 0;
    }
    if (memo[first][length] != INF) {
        return memo[first][length];
    }
    ll a, b;
    a = func(first, length - 1);
    b = func(first + 1, length - 1);
    memo[first][length] = max(-a + as[length - 1 + first], -b + as[first]);
    return memo[first][length];
}
int main() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> as;
    char now = s[0];
    ll cnt = 0;
    if (s[0] == '0') {
        as.push_back(0);
    }
    REP(i, s.size()) {
        if (s[i] != now) {
            now = s[i];
            as.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
        if (i == s.size() - 1) {
            as.push_back(cnt);
        }
    }
    vector<ll> las(as.size() + 1);
    for (ll i = 0; i < as.size(); i++) {
        las[i + 1] += las[i] + as[i];
        // cout <<
    }
    ll maxans = 0;
    for (ll i = 0; i < as.size(); i += 2) {
        maxans = max(maxans, las[min(2 * k + 1 + i, (ll)as.size())] - las[i]);
    }
    cout << maxans << endl;
}