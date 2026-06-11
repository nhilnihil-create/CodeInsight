#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10ll+ch-'0';ch=getchar();}
	return x*f;
}
bitset<4000001> f;
int n,a[2010],_;
signed main(){
	n=read();
	f[0]=1;
	for (int i=1,x;i<=n;i++) x=read(),f|=(f<<x),_+=x;
	for (int i=_/2+(_%2?1:0);i<=_;i++){
		if (f[i]){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
