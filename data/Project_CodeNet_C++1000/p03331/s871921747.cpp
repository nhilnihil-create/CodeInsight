#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
using namespace std;
const int N=1e5+100;
int n,ans;
int get(int x)
{
	int cnt=0;
	while (x) cnt+=x%10,x/=10;
	return cnt;
}
signed main()
{
	scanf("%lld",&n);ans=inf;
	for (int i=1;i<n;i++) ans=min(ans,get(i)+get(n-i));
	printf("%lld\n",ans);
}