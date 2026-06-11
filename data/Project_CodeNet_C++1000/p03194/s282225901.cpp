#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define rg register
using namespace std;
template<typename T>inline void in(T &a)
{
	T ch=getchar(),f=1;
	for(a=0;!isdigit(ch);ch=getchar())
	  ch=='-'?f=-1:f=f;
	for(;isdigit(ch);ch=getchar())
	  a=(a<<3)+(a<<1)+ch-'0';
	a*=f;
}
template<typename T>inline void print(T x)
{
	if(x<0)
	  x=-x,putchar('-');
	if(x>9)
	  print(x/10);
	putchar(x%10+'0');
}
long long p,n,tot;
long long a[10000000][2];
long long kk;
inline void prim()
{
	long long sq=sqrt(p)+1;
	for(rg long long i=2;i<=sq;i++)
	if(p%i==0)
    {  
       	kk=0;
       	tot++;
       	a[tot][1]=i;
	    while(p%i==0)  
        {
            a[tot][0]=++kk;
            p/=i;  
        } 
    }
}
inline int power(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a*=a)
	if(b&1) ans*=a;
	return ans;
}
signed main()
{
	cin>>n>>p;
	if(n==1)
	{
		cout<<p<<endl;
		return 0;
	}
	a[++tot][0]=n,a[tot][1]=1;
	prim();
	long long ans=1,tmp;
	for(rg long long i=tot;i>=1;i--)
	if(n<=a[i][0])
	{
		tmp=a[i][0]/n;
		ans*=power(a[i][1],tmp);
	}
	cout<<ans<<endl;
	return 0;
}