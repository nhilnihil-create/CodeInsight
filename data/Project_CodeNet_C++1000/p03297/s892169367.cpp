#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long a,b,c,d;
long long gcd(long long x,long long y){
	if(x>y) swap(x,y);
	while(y){
		long long temp=y;
		y=x%y;
		x=temp;
	}
	return x;
}
int main(){
//	printf("%lld\n",gcd(9,6));
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a<b){
			printf("No\n");
			continue;
		}
		if(a>=c){
			long long e=a-c;
			e%=b;
			long long f=e+c;
		/*	if(f<b){
				printf("No\n");
				continue;
			}*/
			f-=b;
			long long h=gcd(b,d);
			long long k=c-f;
			long long n=k%h;
			n=h-n;
			if(c+n<b){
				printf("No\n");
				continue;
			}
			long long t=f%h;
			if(t+d<b){
				printf("No\n");
				continue;
			}
			printf("Yes\n");
		}
		else{
			long long f=a-b;
			long long h=gcd(b,d);
			long long k=c-f;
			long long n=k%h;
			n=h-n;
			if(c+n<b){
				printf("No\n");
				continue;
			}
			long long t=f%h;
			if(t+d<b){
				printf("No\n");
				continue;
			}
			printf("Yes\n");
		}
	}
	return 0;
}