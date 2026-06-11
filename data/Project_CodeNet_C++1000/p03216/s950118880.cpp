#include <bits/stdc++.h>
#define LL long long
#define MAXN 1000005
using namespace std;

int n, q, k;
LL cnt[MAXN][4];
char s[MAXN];

void init()
{
	for(int i=1; i<=n; i++)
	{
		cnt[i][1]+=cnt[i-1][1];
		cnt[i][2]+=cnt[i-1][2];
		cnt[i][3]+=cnt[i-1][3];
		if(s[i]=='M') cnt[i][2]++;
		if(s[i]=='C') cnt[i][3]++, cnt[i][1]+=cnt[i][2];
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s+1);
	init();
	scanf("%d", &q);
	for(int i=1; i<=q; i++)
	{
		LL ans=0;
		scanf("%d", &k);
		for(int j=1; j<=n; j++)
			if(s[j]=='D')
			{
				ans+=cnt[min(n, j+k-1)][1]-cnt[j-1][1]-cnt[j-1][2]*(cnt[min(n, j+k-1)][3]-cnt[j-1][3]);
			}
		printf("%lld\n", ans);
	}	
} 