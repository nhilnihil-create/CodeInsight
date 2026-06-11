#include<bits/stdc++.h>
using namespace std;
bitset<2000005>bit;
int sum,n,x;
int main(){
	scanf("%d",&n);
	bit[0]=1;
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		bit|=(bit<<x);
		sum+=x;
	}
	for(int i=(sum+1)/2;i<=sum;++i){
		if(bit[i]){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}