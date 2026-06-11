#include<bits/stdc++.h>
#define N 2005
using namespace std;
inline int read(){
	int x=0; bool f=1; char c=getchar();
	for(;!isdigit(c); c=getchar()) if(c=='-') f=0;
	for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	if(f) return x; return 0-x;
}
int n,sum;
bitset<N*N> b; 
int main(){
	n=read();
	int a; b[0]=1;
	for(int i=1; i<=n; ++i){
		a=read();
		b|=b<<a;
		sum+=a;
	}
	for(int i=(sum+1)/2; i<=sum; ++i) if(b[i]){printf("%d\n",i); return 0;}
	return 0;
}
