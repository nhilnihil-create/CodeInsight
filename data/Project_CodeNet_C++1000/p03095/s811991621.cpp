#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>

#define MOD (1000000007)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];


ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


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


int main() {
    ll N;
    cin >> N;

    string S;
    cin >> S;

    map<char, ll> m;
    for(ll i = 0; i < S.size(); i++){
        m[S[i]]++;
    }

    ll ret = 1; // modpow(2, S.size(), MOD) ;

    for(auto itr=m.begin(); itr != m.end(); itr++) {
        ret *= (((itr->second) % MOD )+ 1) % MOD;
        ret %= MOD;
    }

    cout << ret - 1 << endl;

    // ll left = 0, right = 0;
    // map<char, ll> m;
    // ll ret = 0;

    // m[S[left]] = 1;
    // //ret++;
    // while(right <= N) {

    //     if(m[S[right]] >= 2) {
    //         cout << left << "," << right << "-> clear()" << endl;
    //         m.clear();
    //         left = right;
    //         m[S[left]] = 1;
    //     } else {
    //         ret += (right+1)-left;
    //         cout << left << "," << right << "-> +" <<(right+1)-left << endl;
    //         right++;
    //         m[S[right]]++;
    //     }
    // }

    return 0;
}
