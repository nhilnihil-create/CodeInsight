#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
ll a[N],l,r;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	l=r=2;
	for(int i=n;i>=1;--i){
		l=(l-1)/a[i]+1,r=r/a[i];
		if(l>r){
			return !printf("-1\n");
		}
		l=l*a[i],r=(r+1)*a[i]-1;
	}
	printf("%lld %lld\n",l,r);
	return 0;
}

