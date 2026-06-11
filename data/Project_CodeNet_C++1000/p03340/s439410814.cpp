#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+2;
typedef long long ll;
int a[maxn];

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	ll ans = 0;
	int tot = 0;
	int l=0,r=0;
	
	while(1)
	{

		while(r<n && !(tot&a[r]))
		{
			tot+=a[r++];
			
		}
		//if(r>=n) break;
		ans+=r-l;
		//cout<<l<<" "<<r<<"\n";
		tot-=a[l++];
		if(l>=n) break;
	}
	printf("%lld\n",ans);
}