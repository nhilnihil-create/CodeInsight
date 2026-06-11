#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

const int MAX = 1000001;
const int MOD = 1000000007;

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

int main(void){
    int N; cin >> N;
    int ans = 0;
    int A[N][N];
    rep(i, N){
        string S; cin >> S;
        rep(j, N){
            A[i][j] = S[j] - 'a';
        }
    }
    int B[N][N];
    
    for(int b = 0; b < N; b++){
        bool ok = true;
        rep(i, N){
            rep(j, N){
                int x1 = i, y1 = (j+b) % N;
                int x2 = j, y2 = (i+b) % N;
                if(A[x1][y1] != A[x2][y2]) ok = false;
            }
        }
        if(ok) ans += N;
    }
    cout << ans << endl;
    return 0;
}