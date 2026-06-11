#include <bits/stdc++.h>
using namespace std;
#define N 2001000

int n,q,m;
char s[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (scanf("%d",&q);q;q--) {
		scanf("%d",&m);
		int l=1,r=0,sm=0,sc=0;
		long long res=0,ans=0;
		for (;r<m;r++) {
			if (s[r+1]=='C') res+=sm,sc++;
			if (s[r+1]=='M') sm++;
		}
		for (;l<=n;l++,r++) {
			if (s[l]=='D') ans+=res;
			if (s[l]=='M') res-=sc,sm--;
			if (s[l]=='C') sc--;
			if (s[r+1]=='M') sm++;
			if (s[r+1]=='C') res+=sm,sc++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}