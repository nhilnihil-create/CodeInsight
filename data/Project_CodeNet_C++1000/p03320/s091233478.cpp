#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[105000],k;
signed main(){
	int cnt=0;
	for (int i=1;i<=9;++i)
		f[++cnt]=i;
	for (int i=1;i<=9;++i)
		f[++cnt]=i*10+9;
	for (int i=1;i<=9;++i)
		f[++cnt]=i*100+99;
	int x=10;
	for (int t=1;t<=9;++t){
		x*=10;
		for (int i=10;i<=t*10+9;++i)
			f[++cnt]=(i+1)*x-1;
		int y=t+1;
		while(y<=9) f[++cnt]=(y+1)*x*10-1,y++;	
	}
	x*=10;
	for (int i=10;i<=99;++i)
		f[++cnt]=(i+1)*x-1;
	x*=10;
	for (int i=10;i<=99;++i)
		f[++cnt]=(i+1)*x-1;
	for (int t=10;t<=11;++t){
		for (int i=100;i<=t*10+9;++i)
			f[++cnt]=(i+1)*x-1;
		int y=t+1;
		while(y<=99) f[++cnt]=(y+1)*x*10-1,y++;	
		x*=10;
	}
	scanf("%lld",&k);
	for (int i=1;i<=k;++i)
		printf("%lld\n",f[i]);
}