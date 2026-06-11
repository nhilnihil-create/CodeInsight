#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long 
using namespace std; 
inline char get(){
	const int TOP=1000000;
	static char T[TOP],*x=T,*y=T;
	return x==y&&(y=(x=T)+fread(T,1,TOP,stdin),x==y)?EOF:*x++;
}
inline ll read (){
	register ll num;int sign=1;register char c;
	while (((c=get())<'0'||c>'9')&&c!='-');c=='-'?num=sign=0:num=c-48;
	while ((c=get())>='0'&&c<='9')num=(num<<3)+(num<<1)+(c-48);
	return sign?num:-num;
}
ll n,m,ans=1;
int main(){
	n=read();m=read();
	for(ll i=2;i*i<=m;++i){
		if(m%i==0){
			int s=0;
			while(m%i==0){m/=i;s++;}
			for(int j=1;j<=s/n;++j)ans*=i;
		}
	}
	if(m>1)if(n==1)ans*=m;
	printf("%lld\n",ans);
}