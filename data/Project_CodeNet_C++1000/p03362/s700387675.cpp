#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <functional>
#include <list>

#define MOD (1000000000 + 7)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;
const int MAX = 3000000;

long long fac[MAX], finv[MAX], inv[MAX];

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

map<ll,ll> prime;//素因数分解でそれぞれの素数がいくつ出てきたかを保存するmap

//O(√n)
//整列済み(mapはkeyで自動で整列される)
void prime_factorize(ll n){
    if(n<=1) return;
    ll l=sqrt(n);
   for(ll i=2;i<=(ll)(l);i++) { //
        if(n%i==0){
            prime_factorize(i);prime_factorize(ll(n/i));return;
        }
    }
    //mapでは存在しないkeyの場合も自動で構築される
    prime[n]++;return;
} 

vector<ll> divisor;
void list_divisor(ll n) {
    divisor.clear();
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            divisor.push_back(i);
            if(i*i != n) divisor.push_back(n/i);
        }
    }
    sort(divisor.begin(), divisor.end());
}

vector<bool> Eratosthenes(ll N) {
    vector<bool> primes(N, true);
    vector<ll> ret;
    primes[0] = false;
    primes[1] = false;
    for (ll i=2; pow(i,2)<=N; i++) {
        if (primes[i]) {
            for(int j=2; i*j<=N; j++) primes[i*j] = false;
            ret.push_back(primes[i]);
        }
    }
    return primes;//ret;
}

template <typename T> bool next_combination(const T first, const T last, int k) {
    // ** Sample **
    // vector<int> v{1, 2, 3, 4, 5, 6, 7};
    // do {
    //     for (int i = 0; i < k; i++) {
    //         cout << v[i] << " ";
    //     }
    //     cout << "| ";
    //     for (int i = k; i < v.size(); i++) {
    //         cout << v[i] << " ";
    //     }
    //     cout << endl;
    // } while(next_combination(v.begin(), v.end(), k));

    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

int main() {
    ll N;
    cin >> N;

    vector<bool> ans = Eratosthenes(55555);
    vector<ll> primes;
    for(ll i = 0; i < ans.size(); i++) {
        if(ans[i] && i % 5 == 1) primes.push_back(i);
    }


    for(ll i = 0; i < N; i++) {
        cout << primes[i] << " " ;
    }
    cout << endl;
    return 0;

}
