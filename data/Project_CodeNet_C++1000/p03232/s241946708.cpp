#include <cstdio>
#define mod 1000000007

int v[101000]; 
int sum[101000];
int inv[101000], fac[101000];

int main()
{
	inv[0] = inv[1] = fac[0] = 1;
	for(int i = 2; i <= 100000; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= 100000; i++) sum[i] = (sum[i - 1] + inv[i]) % mod;
	for(int i = 1; i <= 100000; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = (ans + 1ll * (sum[i] + sum[n - i + 1] - 1) * v[i]) % mod;
	}
	printf("%lld\n", 1ll * ans * fac[n] % mod);
	return 0;
}

/*
P(i,j)表示当i被删除时，i,j在同一个连通块中的概率 
在删除序列中，i+1~j（或j~i-1）都必须在i之后被删除
由于删除序列均匀随机，所以考虑把i插到i+1~j(或j~i-1)的序列中
有|i-j|+1个空，只有插到第1个空有贡献，所以P(i,j)=1/(|i-j|+1)
ans = n! * ∑i∑j P(i,j)*v[j]
	= n! * ∑j(∑i P(i,j))*v[j]
把1/i拿去前缀和 
*/