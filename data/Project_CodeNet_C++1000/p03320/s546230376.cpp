#include<bits/stdc++.h>
using namespace std;
double pan(long long x){
	long long sum=0,kkk=x;
	while(kkk){
		sum+=kkk%10;
		kkk/=10;
	}
	return x*1.0/(sum*1.0);
}
int main(){
	long long now=0,x=1,k;
	scanf("%lld",&k);
	while(k--){
		if((now/x)%10!=9){
			now+=x;
			printf("%lld\n",now);
		}
		else{
			if(pan(now+x)>pan(now+x*10))x*=10;
			now+=x;
			printf("%lld\n",now);
		}
	}
}