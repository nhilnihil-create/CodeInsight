#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <bitset>
#define M 2005
using namespace std;
int n,a[M],cnt;
bitset <4000005> F;
int read(){
	char c=getchar();int ans=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans;
}
int main(){
	n=read();F[0]=1;
	for (register int i=1;i<=n;i++) a[i]=read(),cnt+=a[i],F|=(F<<a[i]);
	for (register int i=(cnt+1)/2;i<=cnt;i++)
	    if (F[i]){printf("%d",i);break;}
	return 0;
}
