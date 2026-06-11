#include<bits/stdc++.h>

using namespace std;

#define LL long long

LL n;

LL S(LL x){
	LL ret=0;
	for (;x;x/=10) ret+=x%10;
	return ret;
}

int main(){
	scanf("%lld",&n);
	LL x=1;
	while (n--){
		printf("%lld\n",x);
		LL y=0;
		for (LL i=1;i<=1000000000000000;i*=10)
			if (y==0||(x+i)*S(y)<y*S(x+i)) y=x+i;
		x=y;
	}
	
	return 0;
}
			