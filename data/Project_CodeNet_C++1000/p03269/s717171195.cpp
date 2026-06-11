#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)

int L,l;

int main(){
	scanf("%d",&L);
	while(L>>l) ++l;
	printf("%d %d\n",l,l+l+__builtin_popcount(L)-3);
	F(i,1,l-1) printf("%d %d 0\n",i,i+1), printf("%d %d %d\n",i,i+1,1<<i-1);
	int S=1<<l-1;
	dF(i,l-2,0) if(L>>i&1){
		printf("%d %d %d\n",i+1,l,S);
		S|=1<<i;
	}
	return 0;
}