#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,a,b,c,ans;
int main(){
	a=read(),b=read(),c=read(),n=read();
	for(int i=0;i*a<=n;++i){
		for(int j=0;i*a+j*b<=n;++j){
			if((n-i*a-j*b)%c==0)++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}


