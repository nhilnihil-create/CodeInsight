#include <algorithm>
#include <cstdio>
typedef long long ll; 
ll seq[1000005]; 
inline int sum(ll n)
{
	int res = 0; 
	while (n)
	{
		res += n % 10; 
		n /= 10; 
	}
	return res; 
}
int main()
{
	// freopen("ARC099-D.in", "r", stdin); 
	int cnt = 0, n;
	scanf("%d", &n);
	for (int i = 1; i <= 999; i++)
	{
		ll cur = i; 
		while (cur <= 1e15)
		{
			seq[cnt++] = cur; 
			cur = cur * 10 + 9; 
		}
	}
	std::sort(seq, seq + cnt); 
	cnt = std::unique(seq, seq + cnt) - seq; 
	for (int i = 0; i < cnt; i++)
	{
		bool f = true; 
		for (int j = i + 1; j < cnt && f; j++)
		{
			int x = sum(seq[i]), y = sum(seq[j]); 
			if (seq[i] * y > seq[j] * x)
				f = false; 
		}
		if (f && n)
		{
			printf("%lld\n", seq[i]);
			n--; 
		}
	}
	return 0; 
}
