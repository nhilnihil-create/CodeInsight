#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
long long mod = 1000000007;
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define rep(i, a, n) for (long long i = a; i < (n); i++)
long long modpow(long long m, long long n, long long modvalue) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2, modvalue);
        return t * t % modvalue;
    } else {
        return modpow(m, n - 1, modvalue) * m % modvalue;
    }
}
bool bitcheck(ll x, ll y) { return (x >> y) & 1; }

template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
// long long mod = 998244353;

long long moddiv(long long a, long long b, ll modvalue) { return (a * modpow(b, mod - 2, modvalue)) % modvalue; }

const ll INF = 1LL << 60;

void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
}

ll nCkmod(ll n, ll k, ll modvalue) {
    ll numera = 1;
    for (int i = n; i > n - k; i--) {
        numera *= i;
        numera %= modvalue;
    }
    ll denomi = 1;
    REP(i, k) {
        denomi *= (i + 1);
        denomi %= modvalue;
    }
    return moddiv(numera, denomi, modvalue);
}
map<ll, ll> cnt;
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
int main() {
    ll n;
    cin >> n;
    vector<ll> v1(n / 2);
    vector<ll> v2(n / 2);
    vector<P> cnt1(100006);
    vector<P> cnt2(100006);
    REP(i, n) {
        if (i % 2 == 0) {
            cin >> v1[i / 2];
            cnt1[v1[i / 2]].second = v1[i / 2];
            cnt1[v1[i / 2]].first++;
        }
        if (i % 2 == 1) {
            cin >> v2[i / 2];
            cnt2[v2[i / 2]].second = v2[i / 2];
            cnt2[v2[i / 2]].first++;
        }
    }
    sort(cnt1.rbegin(), cnt1.rend());
    sort(cnt2.rbegin(), cnt2.rend());
    if (cnt1[0].second != cnt2[0].second) {
        cout << n - cnt1[0].first - cnt2[0].first << endl;
    } else {
        cout << min(n - cnt1[0].first - cnt2[1].first, n - cnt2[0].first - cnt1[1].first) << endl;
    }
}