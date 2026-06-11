#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,sum;
ll ans=1,p=1;
ll calc(ll x){
	if(!x)return 0;
	else return calc(x/10)+x%10;
}
int main(){
	scanf("%d",&k);
	while(sum<k){
		printf("%lld\n",ans);
		ll x=ans+p,y=ans+p*10;
		if(x*calc(y)<=y*calc(x))ans=x;
		else{
			ans=y;
			p*=10;
		}
		sum++;
	}
	return 0;
}