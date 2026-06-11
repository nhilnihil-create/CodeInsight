//Modular Inverse Template by Le Tang Phu Quy
#include<bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define taskname "test"
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define LL long long
#define MOD 998244353
#define INF 1000000000000000000
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

using namespace std;

const int maxN = 1e6+5;
LL fact[maxN], ifact[maxN];
LL powerMod(LL a, LL n, LL m);
void computeFactorials(int N);
LL combination(int n, int k);

int main()
{
	FASTIO;
	computeFactorials(maxN-4);
    LL N,A,B,K;
    cin >> N >> A >> B >> K;
    if (A<B) swap(A, B);
    int lim = min(N, K/A);
    LL ans = 0;
    for (int x=0; x<=lim; x++) {
        if ((K-A*x)%B) continue;
        int y = (K-A*x)/B;
      	if (y > N) continue;
        LL nWays = (combination(N,x) * combination(N,y)) % MOD;
        ans += nWays;
        ans %= MOD;
    }
    cout << ans;
	return 0;
}

LL powerMod(LL a, LL n, LL m) {
	if (n==0) return 1;
	if (n==1) return (a%m);
	LL ans = powerMod(a,n/2,m);
	ans *= ans, ans %= m;
	if (n%2) ans *= a, ans %= m;
	return ans;
}

void computeFactorials(int N) {
	fact[0]=1;
	for (int i=1; i<=N; i++)
		fact[i] = (i*fact[i-1])%MOD;
	ifact[N] = powerMod(fact[N], MOD-2, MOD);
	for (int i=N-1; i>=0; i--)
		ifact[i] = ((i+1)*ifact[i+1])%MOD;
}

LL combination(int n, int k) {
	return  ((fact[n]*ifact[k])%MOD * ifact[n-k])%MOD;
}
    