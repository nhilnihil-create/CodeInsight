#include <bits/stdc++.h>
using namespace std;


const int MAX = 510000;
const int mod = 998244353;

long long fac[MAX]; //i!%mod=fac[i]
long long finv[MAX]; //pow(i!,-1)%mod=finv[i]
long long inv[MAX]; //pow(i,-1)%mod=inv[i]

// テーブルを作る前処理
void cominit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(int argc, char const *argv[])
{
	cominit();
	int n;
	long long a,b,k;
	cin>>n>>a>>b>>k;
	long long ans=0LL;
	for (long long i = 0; i <= n; ++i)
	{
		if ((k-a*i)%b==0&&(k-a*i)/b<=n)
		{
			long long j=(k-a*i)/b;
			ans+=com(n,i)*com(n,j)%mod;
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
