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
    ll N, M;
    cin >> N >> M;

    map<int, vector<pair<int,int>>> m;
    for(int i = 0; i < M;i++) {
        ll P, Y;
        cin >> P >> Y;
        m[P].push_back(make_pair(Y, i));
    }

    vector<pair<int,int>> v(M);
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        sort(itr->second.begin(), itr->second.end());
        
        //for(auto itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++) {
        for(int i = 0; i < itr->second.size(); i++) {
            v[itr->second[i].second] = make_pair(itr->first, i);
        }
    }

    for(int i = 0; i < M; i++) {
        cout << setw(6) << setfill('0')  << v[i].first <<  setw(6) << setfill('0')  << v[i].second + 1 << endl;
    }




    return 0;
}
