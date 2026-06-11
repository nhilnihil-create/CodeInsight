#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;} 
int main(){
	int n=read();
	while(n--){
		long long a=read(),b=read();
		long long fxxk=sqrt(a*b-1);
		if(fxxk*fxxk>a*b-1)fxxk--;
		printf("%lld\n",fxxk*2-(fxxk>=a)-(fxxk>=b)-(fxxk*(fxxk+1)>=a*b));
	}
}