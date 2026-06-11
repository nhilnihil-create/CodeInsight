#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, cur=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=40;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			//cout<<a[j]<<" "<<i<<" "<<(int)(a[j]>>i)<<endl;
			if((a[j]>>i)&1)
				cnt++;
		}
		if(cnt*2<n && (cur+(1LL<<i)<=k))
			cur+=(1LL<<i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=(cur^a[i]);
	cout<<ans<<endl;
	return 0;
}
