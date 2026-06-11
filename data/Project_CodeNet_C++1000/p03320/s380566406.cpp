#include<bits/stdc++.h>
using namespace std;
long long cf(long long x){
	long long s=0;
	while(x){
		s+=x%10;
		x/=10;
	}
	return s;
}
int main(){
	long long ans=1,p=1,k;
	scanf("%lld",&k);
	for(long long i=1;i<=k;i++){
		printf("%lld\n",ans);
		long long a1=ans+p,a2=ans+p*10;
		if(a1*cf(a2)<=a2*cf(a1))
			ans=a1;
		else{
			ans=a2;
			p*=10;
		}
	}
	return 0;
}