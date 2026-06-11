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

#define MOD (1000000007)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;
const int MAX = 3000000;

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

vector<bool> seen;
vector<int> ret;
int main() {
    ll N;
    cin >> N;

    seen.assign(N, false);
    ret.assign(N, 0);
    vector<vector<pair<ll, ll>>> path(N, vector<pair<ll, ll>>());

    for(ll i = 0; i < N-1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        path[u-1].push_back(make_pair(v-1, w));
        path[v-1].push_back(make_pair(u-1, w));
    }

    queue<pair<ll, ll>> q;
    q.push(make_pair(0, 0));

    while(q.size() >= 1) {
        pair<ll, ll> p = q.front(); q.pop();
        ll c_point = p.first;
        ll c_dist = p.second;

        //cout << c_point << "," << c_dist << endl;

        if(c_dist % 2 == 0) ret[c_point] = 0;
        else ret[c_point] = 1;

        for(ll i = 0; i < path[c_point].size(); i++) {
            ll n_point = path[c_point][i].first;
            ll n_dist = path[c_point][i].second;

            if(seen[n_point] == true) continue;
            q.push(make_pair(n_point, c_dist + n_dist));
            seen[n_point] = true;
        }
    }

    for(ll i = 0; i < N; i++) {
        cout << ret[i] << endl;
    }

    
    return 0;    
}


