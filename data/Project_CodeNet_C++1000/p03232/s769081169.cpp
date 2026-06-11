#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
vector<int> dy = {0,0,1,-1};
vector<int> dx = {1,-1,0,0};
ll gcd(ll a, ll b){//計算量はO(log(max(a,b))
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
}
ll pow_MOD(ll x,ll n){//x^n
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    res %= MOD;
    return res;
}
ll mod_inverse(ll a){//逆元
    ll x,y;
    extgcd(a, MOD, x, y);
    return (MOD + x % MOD) % MOD;
}

const int MAX = 200010;
ll fac[MAX], finv[MAX], inv[MAX];
//facはn!,finvは1/n!
//invは逆元
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}

//素数判定O(√n)
bool Prime(ll n){
    if(n <= 1){
        return 0;
    }
    bool a = true;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            a = false;
        }
    }
    return a;
}

//素因数分解O(√n)
vector<pair<ll, int>> MakePrimeList(ll x){
    vector<pair<ll, int>> PrimeList;
    for(int i = 2; i < 32000; i++){
        if(Prime(i) == 0) continue;
        int cnt = 0;
        while(x % i == 0){
            cnt++;
            x /= i;
        }
        if(cnt){
            PrimeList.push_back({i, cnt});
        }
    }
    if(Prime(x)){
        PrimeList.push_back({x, 1});
    }
    return PrimeList;
}


//約数の列挙O(√n)
vector<ll> divisor(ll n){
    vector<ll> res(0);
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    //sort(res.begin(), res.end());
    return res;
}


//エラトステネスの篩O(n);
int prime[1000010];//i番目の素数
bool is_prime[1000011];
//n以下の素数の個数を全て返す関数
int sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return p;
}
ll kai(int x){
    ll res = 1;
    for(int i = 1; i <= x; i++){
        res = (res * i) % MOD;
    }
    return res;
}

ll S[MAX];
void Sinit(){
    for(int i = 1; i < MAX; i++){
        S[i] = (S[i-1] + mod_inverse(i)) % MOD;
    }
}


int main(void){
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A.at(i);
        A.at(i) %= MOD;
    }
    
    Sinit();
    
    ll res = 0;
    for(int i = 1; i <= N; i++){
        res += A.at(i) * (S[i] + S[N-i+1] - 1);
        res %= MOD;
    }
    cout << (res * kai(N) % MOD + MOD) % MOD;
}
