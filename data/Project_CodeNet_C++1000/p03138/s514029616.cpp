#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 60;

int n, cnt[N];
LL m, a[N];

int main()
{
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i ++ )
	{
		scanf("%lld", &a[i]);
		for (int j = 0; j < M; j ++ ) cnt[j] += (a[i] >> j) & 1;
	}
	
	int maxa = -1;
	for (int i = M - 1; i >= 0; i -- )
		if ((m >> i) & 1)
		{
			if (n - cnt[i] > cnt[i]) cnt[i] = n - cnt[i];
			else
			{
				maxa = i;
				break;
			}
		}
	
	for (int i = maxa - 1; i >= 0; i -- )
		if (n - cnt[i] > cnt[i])
			cnt[i] = n - cnt[i];
	
	LL res = 0;
	for (int i = 0; i < M; i ++ )
		res += (LL)cnt[i] * (1LL << i);
	printf("%lld\n", res);
    return 0;
}