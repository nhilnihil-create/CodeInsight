#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=210000;
int n,ans,vi[N];
char s[N];
bool check(int i){return((s[i]=='B')&(s[i+1]=='C'))|(vi[i]);}
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0;
	for (int i=n-1;i>=1;)
	{
		if (check(i))
		{
			cnt++;
			int j=i-1;
			while (s[j]=='A' && j>0) ans+=cnt,j--;
			i=j-1;
		}
		else cnt=0,i--;
	}
	printf("%lld\n",ans);
}
