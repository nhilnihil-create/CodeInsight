#include<cstdio>
#include<vector>
#include<algorithm>
std::vector<long long> a,ans;
int n;
inline int solve(long long x)
{
	if (!x) return 0;
	return solve(x/10)+x%10;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=8;i++) ans.push_back(1ll*i);
	n=n;
	if (n<=0) return 0;
	for (int i=0;i<=1000;i++)
	{
		long long k=i;
		for (int j=1;j<=16;j++)
		{
			k=k*10+9;
			a.push_back(k);
		}
	}
	double now=1e30;
	std::sort(a.begin(),a.end());
	for (int i=a.size()-1;i>=0;i--)
	    if (a[i]/(double)solve(a[i])<=now) now=a[i]/(double)solve(a[i]),ans.push_back(a[i]);
	std::sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++)
	{
		if (i==0) --n,printf("%lld\n",ans[i]);
		else if (ans[i]!=ans[i-1]) --n,printf("%lld\n",ans[i]);
		if (n==0) break;
	}
	return 0;
}