#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5;
int a[N];s64 s[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n,X;
	cin>>n>>X;
	s64 base=s64(n)*X;
	rep(i,1,n){scanf("%d",a+i);base+=5LL*a[i];}
	rep(i,1,n)s[i]=s[i-1]+a[i];
	s64 mn=s64(n)*X;
	rep(l,1,n)
	{
		s64 now=s64(l)*X;
		for(int i=n-l,k=1;i>0&&now<mn;i-=l,++k)now+=(s[i]-s[max(0,i-l)])*(2*k-2);
		chmin(mn,now);
	}
	cout<<mn+base;
}