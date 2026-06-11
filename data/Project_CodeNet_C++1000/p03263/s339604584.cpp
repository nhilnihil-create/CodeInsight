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
    ll H, W;
    cin >> H >> W;

    vector<vector<int>> a(H+1, vector<int>(W + 1, 0));
    for(int h = 1; h <= H; h++) {
        for(int w = 1; w <= W; w++) {
            cin >> a[h][w];
        }
    }

    int h = 0;
    int w = 0;

    int odd_h = 0;
    int odd_w = 0;

    vector<int> A, B, C, D;

    for(int i = 0; i < H*W; i++) {
        h = (i / W) + 1;
        w =  h % 2 == 1 ? (i % W) + 1 : W - (i%W);

        //cout << h << "<" << w << endl;

        if(a[h][w] % 2 == 1) {
            if(odd_h != 0) {
                A.push_back(odd_h);
                B.push_back(odd_w);
                C.push_back(h);
                D.push_back(w);
                
                //cout << odd_h << " " << odd_w << " " << h << " " << w << endl;
                odd_h = 0;
                odd_w = 0;
            } else {
                odd_h = h;
                odd_w = w;
            }
        } else {            
            if(odd_h != 0) {
                A.push_back(odd_h);
                B.push_back(odd_w);
                C.push_back(h);
                D.push_back(w);
                
                //cout << odd_h << " " << odd_w << " " << h << " " << w << endl;
                odd_h = h;
                odd_w = w;
            }
        }
    }

    cout << A.size() << endl;
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " " << B[i] << " " << C[i] << " " << D[i] << endl;
    }

    return 0;    
}

