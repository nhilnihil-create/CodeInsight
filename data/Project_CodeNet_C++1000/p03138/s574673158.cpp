#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 60, M = 1010;

int n;
LL m, cnt[M];

int main()
{
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i ++ )
	{
		LL t;
		scanf("%lld", &t);
		for (int j = 0; j < N; j ++ ) cnt[j] += (t >> j) & 1;
	}
	
	int u = -1;
	for (int i = N - 1; i >= 0; i -- )
		if (((m >> i) & 1))
		{
			if (cnt[i] >= n - cnt[i])
			{
				u = i;
				break;
			}
			else cnt[i] = n - cnt[i];
		}
	
	for (int i = u - 1; i >= 0; i -- )
		if (cnt[i] < n - cnt[i])
			cnt[i] = n - cnt[i];
	
	LL res = 0;
	for (int i = 0; i < N; i ++ ) res += cnt[i] * (1LL << i);
	printf("%lld\n", res);
    return 0;
}