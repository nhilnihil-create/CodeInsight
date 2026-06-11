#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <functional>

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


int main() {
    ll N;
    cin >> N;

    ll lastA = 0, firstB = 0, lastA_firstB = 0;
    ll count = 0;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;

        auto found = S.find("AB");
        while(found != string::npos) {
            count++;
            found = S.find("AB", found + 2);
        }

        if(S[0] == 'B' && S[S.size()-1] == 'A') lastA_firstB++;
        else if(S[0]=='B') firstB++;
        else if(S[S.size()-1] == 'A') lastA++;
    }

    // cout << count  << endl;
    // cout << firstB << "," << lastA << "," << lastA_firstB << endl;

    if(lastA_firstB >= 1) {
        count += lastA_firstB - 1;
        if(firstB > 0) {
            count += 1;
            firstB--;
        } 
        if(lastA > 0) {
            count += 1;
            lastA--;
        }
    }


    count += min(firstB, lastA);

    cout << count << endl;

    

    return 0;    
}

