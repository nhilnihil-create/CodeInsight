#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[1000000];
int main()
{	int n,sum=3; cin>>n;
	if(n==3) return !printf("2 5 63");
	if(n==4) return !printf("2 5 20 63");
	if(n==5) return !printf("2 5 20 30 63");
	a[1]=2; a[2]=3; a[3]=4; a[4]=6;
	for(rint i=1;;i++)
	for(rint j=i*4+1;j<=i*4+4;j++)
	{	a[j]=a[j-4]+6; (sum+=a[j])%=6;
		if(j==n)
		{	int ban=0; if(sum==3||sum==5) ban=9; if(sum==2) ban=8;
			for(rint k=1;k<=n;k++) if(a[k]!=ban) printf("%d ",a[k]);
			if(sum==2||sum==3) printf("%d ",a[j]-a[j]%6+6);
			if(sum==5) printf("%d ",a[j]-a[j]%6+4);
			return 0;
		}
	}
	return 0;
}
