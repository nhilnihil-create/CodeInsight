#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
#define N 2002
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
int n,a[N],sum;
bitset<N*N> dp;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		sum+=(a[i]=read());
	}
	sum=(sum+1)>>1;
	dp[0]=1;
	for(int i=1;i<=n;++i){
		dp|=dp<<a[i];
	}
	for(int i=sum;;++i){
		if(dp[i]){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}

