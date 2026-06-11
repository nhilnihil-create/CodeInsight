#include<bits/stdc++.h>
using namespace std;
int l;
int main(){
	scanf("%d",&l);
	int n=0,ll=l;
	while (ll){
		ll>>=1;
		n++;
	}
	int y=__builtin_popcount(l)-1;
	printf("%d %d\n",n,(n-1)*2+y);
	for (int i=1;i<n;++i){
		printf("%d %d %d\n",i,i+1,1<<(i-1));
		printf("%d %d %d\n",i,i+1,0);
	}
	int c=1<<(n-1);
	for (int i=n-1;i;--i){
		if ((1<<(i-1))&l) printf("%d %d %d\n",i,n,c),c+=(1<<(i-1));
	}
}