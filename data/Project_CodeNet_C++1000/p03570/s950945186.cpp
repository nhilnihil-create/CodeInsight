#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
typedef long long ll;
using namespace std;
int minn[67108865],f[200001],a[200001];
char c[200001];
const int inf=1e8;
int main()
{	scanf("%s",c+1);
	int n=strlen(c+1);
	for(rint i=1;i<=n;i++) a[i]=a[i-1]^(1<<(c[i]-'a'));
	int all=(1<<26)-1;
	for(rint i=1;i<=all;i++) minn[i]=inf;
	for(rint i=1;i<=n;i++)
	{	f[i]=minn[a[i]]+1;
		for(rint j=0;j<26;j++) f[i]=min(f[i],minn[a[i]^(1<<j)]+1);
		minn[a[i]]=min(minn[a[i]],f[i]);
	}
	cout<<f[n]<<endl;
 	return 0;
}
