#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll k,now=0,del=1,tot=0;
double s(ll x){
	ll sum=0,d=x;
	while(d){sum+=(d%10);d/=10;}
	return (double)x/(double)sum;
}
int main(){
	scanf("%lld",&k);
	while(tot<k){
		if((now/del)%10==9){
			if(s(now+del)>s(now+10*del))  del*=10;
		}
		now+=del;printf("%lld\n",now);tot++;
	}
	return 0;
}