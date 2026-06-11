#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=200005;
typedef unsigned long long ull;
inline ull F(ull i,ull x)
	{
		return i==1?5*x:x*(2*i+1);
	}
ull s[N];
int main()
{
//freopen("input.txt","r",stdin);
int n;
ull x;
cin >>n>>x;
for(int i=1;i<=n;i++)
	scanf("%lld",&s[i]),s[i]+=s[i-1];
ull ans=ull(1)<<62;
for(int i=1;i<=n;i++)
	{
		int now=n,j=1;
		ull res=0;
		while(now>=i)
			{
				res+=F(j,s[now]-s[now-i]);
				now=now-i;
				j++;
			}
		res+=F(j,s[now]-s[0]);
		ans=min(res+i*x,ans);
	}
cout <<ans+n*x;
return 0;
}
