#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2010;
int a[N];
bitset <N*N> f;
int main(){
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),m+=a[i];
	for(int i=1;i<=n;++i) f|=f<<a[i];
	for(int i=(m+1)/2;i<=m;++i){
		if(f[i]){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}