#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,x,y,t;
bitset<4000100>f;
int main(){
	scanf("%d",&n);f|=1;
	for (i=1;i<=n;i++){ scanf("%d",&x); f|=f<<x; t+=x; }
	for (i=t+1>>1;i<=t;i++)if (f[i])return printf("%d ",i),0;
}