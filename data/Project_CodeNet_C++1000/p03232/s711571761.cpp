#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

typedef pair<int, int> p;

const int mod = 1e9+7;
const int AC=100010;

long long n,ans,res=1;
long long a[AC],b[AC],t[AC],s[AC];

inline void read(long long &x)
{
	long long f=1;
	char s=getchar();
	x=0;
	while ( s<'0' || s>'9' )
	{
		if ( s=='-' ) f=-1;
		s=getchar();
	}
	while ( s>='0' && s<='9' )
	{
		x=x*10+s-'0';
		s=getchar();
	}
	x*=f;
}

inline long long quick(long long a,long long b)
{
	long long base=a,ans=1;
	while ( b )
	{
		if ( b&1 ) ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
} 

long long inv(long long n){
	return quick(n, mod-2);
}

int main(){
	read(n);
	for ( int i=1;i<=n;i++ )
	{
		read(a[i]);
	}
	for ( int i=1;i<=n;i++ )
	{
		s[i]=(s[i-1]+inv(i))%mod;
	}
	for ( int i=1;i<=n;i++ )
	{
		b[i]=(s[n-i+1]+s[i]-1)%mod;
	}	
	for ( int i=1;i<=n;i++ )
	{
		t[i]=(b[i]*a[i])%mod;
	}
	for ( int i=1;i<=n;i++ )
	{
		ans=(ans+t[i])%mod;
	}
	for (int i=1;i<=n;i++ )
	{
		res=(res*i)%mod;
	}
	ans=(ans*res)%mod;
	printf("%lld\n", ans);
	return 0;
}