#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<string, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

string s;
int sum_a[100100], sum_b[100100], sum_c[100100];
int sum_ab[100100], sum_bc_rev[100100], sum_abc[100100];
int sum_q[100100];

ll mod_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll mod_inverse(ll x) {
    return mod_pow(x, mod-2);
}

// nが大きく、kが小さい場合
ll mod_comb(ll n, ll k) {
    if (n < k)
        return 0LL;
    ll nume = 1;
    ll deno = 1;
    if (k > n-k) {
        k = n - k;
    }
    for (ll i = 1; i <= k; i++) {
        nume = nume * (n-i+1) % mod;
        deno = deno * i % mod;
    }
    return nume * mod_inverse(deno) % mod;
}

ll num_a(int l, int r) {
    return sum_a[r] - sum_a[l];
}
ll num_b(int l, int r) {
    return sum_b[r] - sum_b[l];
}
ll num_c(int l, int r) {
    return sum_c[r] - sum_c[l];
}
ll num_q(int l, int r) {
    return sum_q[r] - sum_q[l];
}

ll solve() {
    const int l = (int)s.size();
    for (int i = 1; i <= l; i++) {
        sum_a[i] = sum_a[i-1] + (int)(s[i-1]=='A');
        sum_b[i] = sum_b[i-1] + (int)(s[i-1]=='B');
        sum_c[i] = sum_c[i-1] + (int)(s[i-1]=='C');
        sum_q[i] = sum_q[i-1] + (int)(s[i-1]=='?');
    }
    for (int i = 2; i <=l; i++) {
        sum_ab[i] = (sum_ab[i-1] + (s[i-1]=='B'?sum_a[i-1]:0)) % mod;
    }
    for (int i = 3; i <= l; i++) {
        sum_abc[i] = (sum_abc[i-1] + (s[i-1]=='C'?sum_ab[i-1]:0)) % mod;
    }
    for (int i = l-1; i >= 0; i--) {
        sum_bc_rev[i] = (sum_bc_rev[i+1] + (s[i]=='B'?num_c(i+1, l):0)) % mod;
    }


    ll res = 0;
    const ll q = num_q(0, l);

    // ? 0コ
    res += sum_abc[l] * mod_pow(3, q);
    res %= mod;
    // ? 1コ
    for (int i = 0; i < l; i++) {
        if (s[i] == '?') {
            // A
            res += sum_bc_rev[i+1] * mod_pow(3, q-1);
            res %= mod;
            // B
            ll tmp = (num_a(0, i) * num_c(i+1, l)) % mod;
            tmp *= mod_pow(3, q-1);
            tmp %= mod;
            res += tmp;
            res %= mod;
            // C
            res += sum_ab[i] * mod_pow(3, q-1);
            res %= mod;
        }
    }
    // ? 2コ
    for (int i = 0; i < l; i++) {
        if (s[i] == 'A') {
            res += mod_comb(num_q(i+1, l), 2) * mod_pow(3, q-2);
            res %= mod;
        } else if (s[i] == 'B') {
            ll tmp = (num_q(0, i) * num_q(i+1, l)) % mod;
            tmp *= mod_pow(3, q-2);
            tmp %= mod;
            res += tmp;
            res %= mod;
        } else if (s[i] == 'C') {
            res += mod_comb(num_q(0, i), 2) * mod_pow(3, q-2);
            res %= mod;
        }
    }
    // ? 3コ
    if (q >= 3) {
        res += mod_comb(q, 3) * mod_pow(3, q-3);
        res %= mod;
    }

    
    return res;
}

void input() {
    cin >> s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
