#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
const int MM = 1e9;
const int MOD = 1e9+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
// priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > pq;

template<typename T> //最大公約数
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T> //最小公倍数
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

const int COM_MAX = 500500;
long long fac[COM_MAX],finv[COM_MAX],inv[COM_MAX];
void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < COM_MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

long long nCr(int n,int k){
    if(n < k || n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}


// a^n mod を計算する
long long modpow(long long a, long long n, long long MOD) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long Mod) {
    return modpow(a, Mod - 2, Mod);
}


bool IsPrime(int x){
    for (int i = 2; i*i <= x; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

vector<pair<ll, ll> > PrimeFactor(ll N){
    vector<pair<ll, ll> > prime;
    for (int i = 2; i*i <= N; i++){
        if (N % i != 0) continue;
        int cnt = 0;
        while (N % i == 0){
            cnt++;
            N /= i;
        }
        prime.push_back({i, cnt});
    }
    if (N > 1){
        prime.push_back({N, 1});
    }
    return prime;
}

vector<pair<ll, ll> > CountPrime(ll N){
    vector<pair<ll, ll> > prime;
    for (ll i = 2; i * i <= N; i++){
        if (N % i != 0) continue;
        ll cnt = 0, n = N;
        while (n % i == 0){
            cnt++;
            n /= i;
        }
        prime.push_back({i, cnt});
    }
    prime.push_back({N, 1});
    return prime;
}

int main(){
    ll N, M; cin >> N >> M;
    vector<ll> cake[3];
    ll res = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 3; j++){
            ll num; cin >> num;
            cake[j].push_back(num);
        }
    }

    for (int bit = 0; bit < (1 << 3); bit++){
        vector<ll> b(0);
        for (int i = 0; i < N; i++){
            ll tmp = 0;
            for (int j = 0; j < 3; j++){
                if (bit & (1 << j)) tmp += cake[j][i];
                else tmp -= cake[j][i];
            }
            b.push_back(tmp);
        }

        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());

        ll sum = 0;
        for (int i = 0; i < M; i++){
            sum += b[i];
        }
        //cout << sum << endl;
        res = max(res, sum);
    }
    cout << res << endl;
}