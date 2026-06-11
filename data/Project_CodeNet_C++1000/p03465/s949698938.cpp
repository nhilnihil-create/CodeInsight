#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<bitset>
#define int long long
using namespace std;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
bitset<4001000> w;
int sum=0;
signed main(){
	n=read();
	w[0]=1;
	for(register int i=1;i<=n;i++){
		int x=read();
		w|=w<<x;
		sum+=x;
	}
	for(register int i=(sum+1)/2;i<=sum;i++){
		if(w[i]){
			printf("%lld\n",i);
			return 0;
		}
	}
	return 0;
}