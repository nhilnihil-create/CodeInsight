#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P> > vec;
// vector<vector<int>> data(3, vector<int>(4));

const long long MAX_P = 300001;
const long long MOD = 998244353;

// 入力はすべて正とする
// 素数判定O(√n)
bool is_prime(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;  // 1の場合は例外
}
// 約数の列挙O(√n)
vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}
// 素因数分解O(√n)
map<long long, long long> prime_factor(long long n) {
    map<long long, long long> res;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

long long mod_inverse(long long a, long long m) {
    long long x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

long long fact[MAX_P + 1];
// n! mod pのテーブルを作る O(p)
void mod_fact(long long n, long long m) {
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % m;
}

// n!=a p^e としたときのa mod pを求める。O(log_p n)
long long mod_fact(long long n, long long p, long long& e) {
    e = 0;
    if (n == 0) return 1;
    // pの倍数の部分を計算
    long long res = mod_fact(n / p, p, e);
    e += n / p;
    // (p-1)!≡-1なので(p-1)!^(n/p)はn/pの偶奇だけで計算できる
    if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
    return res * fact[n % p] % p;
}

// nCk mod pを求める。O(log_p n)
long long mod_comb(long long n, long long k, long long p) {
    if (n < 0 || k < 0 || n < k) return 0;
    long long e1, e2, e3;
    long long a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2),
              a3 = mod_fact(n - k, p, e3);
    // if (a1 * mod_inverse(a2 * a3 % p, p) % p == 0) printf("%lld, %lld,
    // %lld,%lld, %lld, %lld\n",n, p, e1,a1, a2, a3);
    if (e1 > e2 + e3) return 0;
    return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

// void solve(long long N, long long M){
// 	map<long long, long long> factorM = prime_factor(M);
// 	long long res = 1;
// 	mod_fact(MAX_P,MOD);
// 	for (auto x : factorM){
// 		//if (mod_comb(N-1+x.second,x.second,MOD) == 0) printf("%lld,
// %lld\n",x.first, x.second); 		if (x.second > 0) res =
// res*mod_comb(N-1+x.second,x.second,MOD)%MOD;
// 	}

// 	printf("%lld\n", res);
// }

void solve(long long N, long long A, long long B, long long K) {
    mod_fact(MAX_P, MOD);
    ll res = 0;
    rep(i, N + 1) {
        if ((K - A * i) % B != 0) continue;
        ll bc = (K - A * i) / B;
        if (bc < 0 || bc > N) continue;
        res = (res + (mod_comb(N, i, MOD) * mod_comb(N, bc, MOD)) % mod) % mod;
    }
    cout << res << endl;
}

int main() {
    long long N;
    long long B;
    long long K;
    long long A;
    scanf("%lld", &N);
    scanf("%lld", &A);
    scanf("%lld", &B);
    scanf("%lld", &K);
    solve(N, A, B, K);
    return 0;
}
