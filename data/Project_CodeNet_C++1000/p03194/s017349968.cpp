#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	long long n,p;
	cin>>n>>p;
	long long jg = pow(p,1.0/n);
	for(long long i = jg+1;;i--){
		if(p%(long long)pow(i,n) == 0){
			jg = i;
			break;
		}
	}
	printf("%lld\n",jg);
	return 0;
}