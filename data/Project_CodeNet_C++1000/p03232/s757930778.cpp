        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 510000;
const int MOD = 1000000007;
//
int fac[MAX], finv[MAX], inv[MAX];

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
int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

        signed main() {
                cout << std::setprecision(12); 
                COMinit();
        int n;
        cin>>n;
        int k[n+1];
        k[1]=1;
        for(int i=2;i<=n;i++)k[i]=(k[i-1]+inv[i])%MOD;
        int a,ans=0;
        for(int i=0;i<n;i++){
                cin>>a;
                ans=(ans+(((k[n-i]+k[i+1]-1)%MOD)*a)%MOD)%MOD;
        }
        cout<<(ans*fac[n])%MOD;

        
        
        


      }


        
