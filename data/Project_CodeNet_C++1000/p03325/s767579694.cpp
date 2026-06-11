#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		while(a[i]%2==0)
		{
			a[i]/=2;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}