#include<cstdio>
#include<iostream>
using namespace std;
int k;
long long ans,power=1;
inline double div(long long x){
	int sum=0;
	long long tmp=x;
	while(tmp>0){
		sum+=tmp%10;
		tmp/=10;
	}
	return 1.0*x/sum;
}
int main(){
	scanf("%d",&k);
	for(register int i=1;i<=k;i++){
		while(div(ans+power)>div(ans+power*10)){
			power*=10;
		}
		ans+=power;
		printf("%lld\n",ans);
	}
	return 0;
}