#include<bits/stdc++.h>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};
const char d[4]={'R','L','D','U'};
const int N=1005;
typedef long long ll;
const ll inf=1e18;
vector<int> vec;
int n,x[N],y[N],s0,s1;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		if ((x[i]+y[i])&1) s1++;else s0++;
	}
	if (s0&&s1) return puts("-1"),0;
	if (s0) puts("32");else puts("31");
	for (int i=30;i>=0;i--)
	  vec.push_back(1<<i),printf("%d ",1<<i);
	if (s0) vec.push_back(1),printf("%d",1);
	puts("");
	for (int i=1;i<=n;i++)
	{
		ll nx=0,ny=0;
		for (int j=0;j<vec.size();j++)
		{ 
		   ll Min=inf,pos;
		   for (int k=0;k<4;k++)
		   {
		   	  ll xx=nx+vec[j]*dx[k],yy=ny+vec[j]*dy[k];
		   	  if ((ll)abs(x[i]-xx)+abs(y[i]-yy)<Min)
		   	  {
		   	  	  Min=(ll)abs(x[i]-xx)+abs(y[i]-yy);
		   	  	  pos=k;
			  }
		   }
		   printf("%c",d[pos]);
		   nx+=vec[j]*dx[pos];ny+=vec[j]*dy[pos];
		}
		puts("");
	}
	return 0;
}