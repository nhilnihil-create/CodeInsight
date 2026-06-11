#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,sum,a[2010];
bitset<4000010>f;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	f[0]=1;
	for(i=1;i<=n;i++){
		f=f|(f<<a[i]);
		sum+=a[i];
	}
	for(i=(sum+1)/2;i<=sum;i++)if(f[i]){
		printf("%d",i);
		return 0;
	}
}