#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,ans=0;
int a[100005];

signed main()
{
	cin>>n;
	n+=2;
	for (int i=2;i<=n-1;i++)  cin>>a[i];
	
	for (int i=1;i<=n-1;i++)  ans+=abs(a[i+1]-a[i]);
	for (int i=2;i<=n-1;i++)  cout<<ans-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1])<<endl;
	
	return 0; 
} 