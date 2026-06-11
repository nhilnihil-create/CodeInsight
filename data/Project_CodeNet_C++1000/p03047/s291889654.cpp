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
int n,k;
int main(){
	n=read(),k=read();
	printf("%d\n",n-k+1);
	return 0;
}


