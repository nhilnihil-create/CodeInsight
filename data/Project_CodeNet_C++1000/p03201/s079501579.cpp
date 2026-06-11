#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+7;
map<int,int> sum;
int n;
ll ans;
int a[maxn],vis[maxn];
bool cmp(int x,int y) {return x>y;}
int main()
{
//    freopen("powers.in","r",stdin);
//	freopen("powers.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin>>n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
//		cin>>a[i];
		scanf("%d",&a[i]);
		sum[a[i]]++;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(sum[a[i]]==0) continue;
//		vis[i]=1;
		int k=1;
		for(int j=1;j<=30;j++) 
		{
			if(k>a[i]) break ; 
			k*=2;
		} 
		int x=k-a[i];
		if(x==a[i])
		{
			if(sum[x]>1)
			{
				sum[x]-=2;
				ans++;
			}
		}
		else
		if(sum[x]>0 && sum[a[i]]>0)
		{
//			cout<<sum[a[i]]<<endl;
			sum[a[i]]--;
			sum[x]--;
			ans++;
		}
//			int x=a[i]-j;
////			cout<<x<<endl;
//			for(int k=1;k<=n;k++)
//			if(a[k]==x && vis[k]!=1)
//			{
////				cout<<i<<' '<<k<<endl;
//				vis[i]=1;
//				vis[k]=1;
//				ans++;
//				break ;
//			}
//			int lb=lower_bound(a+1,a+n+1,a[i]-j)-a;
//			while(a[lb]==a[i]-j && vis[lb]==1) lb--;
//			if(a[lb]==a[i]-j)
//			{
//				vis[i]=1;
//				vis[lb]=1;
//				ans++;
//			}
	}
	cout<<ans;
	return 0;
}
 