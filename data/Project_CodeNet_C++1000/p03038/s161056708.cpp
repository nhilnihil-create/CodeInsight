#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 510000;
const int MOD = 1000000007;

/*long long fac[MAX], finv[MAX], inv[MAX];

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
}*/

int main() {
   int N, M;
   cin >> N >> M;

   vector<ll> A(N), B(M), C(M);
   for(int i = 0; i < N; i++) {
       cin >> A[i];
   }

   for(int i = 0; i < M; i++) {
       cin >> B[i] >> C[i];
   }

   priority_queue<pair<ll, int>> q;

   for(int i = 0; i < M; i++) {
       q.push(make_pair(C[i], B[i]));
   }

   for(int i = 0; i < N; i++) {
       q.push(make_pair(A[i], 1));
   }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        pair<ll, int> p = q.top();
        q.pop();
        ans += p.first;
        p.second--;
        if(p.second > 0) q.push(make_pair(p.first, p.second));
}

    cout << ans << endl;
   
    return 0;
}