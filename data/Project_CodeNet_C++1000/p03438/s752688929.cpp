#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,tot;
int a[200005],b[200005];

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)  cin>>a[i],tot-=a[i];
	for (int i=1;i<=n;i++)  cin>>b[i],tot+=b[i];
	
	if (tot<0)  return cout<<"No"<<endl,0;
	
	for (int i=1;i<=n;i++)
	{
		if (a[i]<b[i])  tot=tot-(b[i]-a[i]+1)/2;
	}
	if (tot<0)  cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	
	return 0; 
}