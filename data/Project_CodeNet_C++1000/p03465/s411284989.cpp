#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,x,sum;
bitset<4000020>f;
int main(){
	scanf("%d",&n);
	f[0]=1;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		f|=f<<x;
		sum+=x;
	}
	for(i=(sum+1)/2;i<=sum;i++)if(f[i]){
		printf("%d",i);return 0;
	}
}