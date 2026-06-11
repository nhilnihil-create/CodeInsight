#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
const int MN=1e5+5;
char s[MN];
int n,rt;bool a[MN];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	reg int i;
	for(i=1;i<=n;++i) a[i]=(s[i]=='1');
	if(!a[1]||a[n]) return 0*puts("-1");
	for(i=1;i<=n-1;++i) if(a[i]!=a[n-i]) return 0*puts("-1");
	for(rt=1,i=2;i<=(n+1)/2;++i)if(a[i])
	{
		printf("%d %d\n",i,rt);
		for(int j=rt+1;j<i;++j) printf("%d %d\n",i,j);
		rt=i;
	}
	printf("%d %d\n",rt+1,rt);++rt;
	for(i=rt+1;i<=n;++i) printf("%d %d\n",rt,i);
	return 0;
}