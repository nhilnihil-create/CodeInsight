#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll s[N];
int main()
{	int n,c; long double ans=1e100; cin>>n>>c;
	for(rint i=1;i<=n;i++) scanf("%lld",&s[i]),s[i]+=s[i-1];
	for(rint i=1;i<=n;i++)
	{	long double sum=ll(n+i)*c;
		for(rint t=1,j=n;j>=1;t++,j-=i)
		sum+=(long double)(t==1?5:2*t+1)*(s[j]-s[max(0,j-i)]);
		ans=min(ans,sum);
	}
	cout<<(ll)ans;
	return 0;
}
