#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

const int N=55;
int x[N],y[N];
int n,k;
int val[N],c;

signed main()
{
	cin>>n>>k;
	for(register int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	
	long long ans=LLONG_MAX;
	for(register int a=1;a<=n;a++)
		for(register int b=1;b<=n;b++)
			for(register int c=1;c<=n;c++)
				for(register int d=1;d<=n;d++)
				{
					int x1=x[a],y1=y[b],x2=x[c],y2=y[d];
					if(x1>x2||y1>y2) continue;
					int cnt=0;
					for(register int i=1;i<=n&&cnt<k;i++)
						if(x1<=x[i]&&x[i]<=x2&&y1<=y[i]&&y[i]<=y2)
							cnt++;
					if(cnt==k) ans=min(ans,(x2-x1)*1ll*(y2-y1));
				}
	cout<<ans<<endl;
	return 0;
}