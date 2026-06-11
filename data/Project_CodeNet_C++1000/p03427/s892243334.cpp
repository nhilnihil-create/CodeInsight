#include<bits/stdc++.h>
using namespace std;
long long n;
int sum,sw,w;
int dsm(long long a){
	int sum=0;
	while(a){
		sum+=a%10;
		if(a<10) sw=a;
		a/=10,w++;
	}
	return sum;
}
int main(){
	scanf("%lld",&n);
	sum=dsm(n);
	printf("%d\n",max(sum,sw+w*9-10));
	return 0;
}