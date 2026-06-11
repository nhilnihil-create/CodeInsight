# include <cstdio>
# include <algorithm>
using namespace std;
const int N = 3e5 + 12;
int l[N],r[N],n;
bool cmp(int x,int y){return x > y;}
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)scanf("%d %d",&l[i],&r[i]);
	sort(l,l + n + 1,cmp);sort(r,r + n + 1);
	for(int i = 0;i <= n;i++)if(l[i] > r[i])ans += 2LL * (l[i] - r[i]);
	printf("%lld\n",ans);
}