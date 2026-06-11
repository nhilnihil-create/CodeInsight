#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)

int main()
{
	//freopen("1.in","r",stdin);
	int n,a,b;
	cin>>n>>a>>b;
	if(!(a+b-1<=n&&(ll)a*b>=n))
	{
		puts("-1");
		return 0;
	}
	int top=0;
	rep(i,1,a)
	{
		int mj=min(b,n-top-(a-i));
		top+=mj;
		rep(j,1,mj)printf("%d ",top-j+1);
	}
}