#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll n,p,maxn=0,k,t;
int Judge(ll x,ll y){
	ll num=0;
	while(y%x==0){
		num++;
		y=y/x;
		if(num>=n)
		    break;
	}
	return num;
}
int main(){
	scanf("%lld %lld",&n,&p);
	if(n==1)
	    printf("%lld\n",p);
	else if(n>=40)
	    printf("1\n");
	else{
		for(ll i=2;;i++){
			k=pow(i,n);
			if(k>=p){
				t=i;
				break;
			}
		}
		for(ll i=2;i<=t;i++){
			ll x=Judge(i,p);
			if(x>=n)
			    maxn=i;
		}
		if(maxn==0)
		    printf("1\n");
		else
		    printf("%lld\n",maxn);
	}
	return 0;
}