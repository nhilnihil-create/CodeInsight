#include<bits/stdc++.h>
using namespace std;
#define next Next
#define int long long
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
#define gc getchar
inline int read()
{
	int ret=0,f=0;char c=gc();
	while(!isdigit(c)){if(c=='-')f=1;c=gc();}
	while(isdigit(c)){ret=ret*10+c-48;c=gc();}
	if(f)return -ret;return ret;
}
int n,i,d=1,s;
int f(int p)
{
	for(s=0;p>=1;p/=10)s+=p%10;
	return s;
}
signed main()
{
	n=read();
	while(n--)
    {
		if((i+d)*f(i+d*2)>(i+d*2)*f(i+d))d*=10;
		i+=d;
		printf("%lld\n",i);
	}
    return 0;
}