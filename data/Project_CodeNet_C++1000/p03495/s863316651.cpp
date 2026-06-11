#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k,pos=0;
int a[200005],visited[200005],cnt[200005];

signed main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=1;i<=n;i++)  visited[a[i]]++;
	for (int i=1;i<=n;i++)
	{
		if (visited[i]>0)  cnt[++pos]=visited[i];
	}
	sort(cnt+1,cnt+pos+1);
	
	if (pos<=k)  cout<<0<<endl;
	else
	{
		int ans=0;
		for (int i=1;i<=pos-k;i++)  ans+=cnt[i];
		cout<<ans<<endl;
	}
	return 0;
}