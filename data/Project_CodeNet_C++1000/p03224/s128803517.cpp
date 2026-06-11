#include<vector>
#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
inline int in()
{
	int k=0;char ch=gt;
	while(ch<'-')ch=gt;
	while(ch>'-')k=k*10+ch-'0',ch=gt;
	return k;
}
const int N=1e5+5;
int n;
std::vector<int>s[N];
void solve(int k)
{
	int now=1;puts("Yes");
	for(int i=1;i<=k;++i)
		for(int j=i+1;j<=k;++j)
			s[i].push_back(now),s[j].push_back(now++);
	printf("%d\n",k);
	for(int i=1;i<=k;++i)
	{
		printf("%d ",k-1);
		for(int j=0;j<k-1;++j)printf("%d ",s[i][j]);
		puts("");
	}
}
int main()
{
	n=in();if(n==1)return puts("Yes\n2\n1 1\n1 1"),0;
	for(int i=1;i*(i-1)/2<=n;++i)
		if(i*(i-1)/2==n)
		{
			solve(i);return 0;
		}
	puts("No");
	return 0;
}
