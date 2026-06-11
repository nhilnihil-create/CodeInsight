#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
long long t,a,b,mul,c,ans;
int main(){
	scanf("%lld",&t);
	for(register int i=1;i<=t;i++){
		scanf("%lld%lld",&a,&b);
		mul=a*b;c=floor(sqrt(mul));
		switch(c*(c+1)<mul){
			case true:ans=2*c-1;break;
			case false:ans=2*c-2;break;
		}
		if(a!=b&&c*c==mul){
			ans--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}