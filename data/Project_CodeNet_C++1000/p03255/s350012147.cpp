#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ldb long double
#define lint long long
#define N 200010
#define gc getchar()
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
int a[N];lint s[N];
inline lint S(int a,int b) { return s[b]-s[max(a-1,0)]; }
int main()
{
	int n=inn(),X=inn();rep(i,1,n) s[i]=s[i-1]+inn();
	a[1]=5;rep(i,2,n) a[i]=2*i+1;ldb ans=1e100;
	rep(k,1,n)
	{
		ldb s=0ll;
		for(int i=n,j=1;i>0;i-=k,j++)
			s+=a[j]*S(i-k+1,i);
		ans=min(ans,s+(lint)X*(n+k));
	}
	return !printf("%lld\n",(lint)ans);
}