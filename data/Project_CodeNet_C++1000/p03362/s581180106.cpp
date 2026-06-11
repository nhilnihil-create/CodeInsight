#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);


// list of prime (is_prime.size() = n + 1, primes.size() = 0)
// primes: list of prime numbers
// is_prime: is_prime[i] == "if i is a prime number"
void prime_list(ll n, vector<ll> &primes, vector<bool> &is_prime) {
    ll p = 0;
    rep(i, n + 1) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;
    for(ll i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(ll j = 2*i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

int main() {
    ll n; cin >> n;
    vector<ll> primes;
    vector<bool> is_prime(56001);
    prime_list(56000, primes, is_prime);
    
    ll num = 0;
    rep(i, primes.size()) {
        if((primes[i]%5) == 1) {
            cout << primes[i];
            num++;
            if(num == n) {
                cout << endl;
                break;
            }
            else {
                cout << " ";
            }
        }
    }

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
