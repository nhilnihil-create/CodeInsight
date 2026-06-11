#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
std::string s;
int k;
int ss(ll x){
	int ret=0;
	while (x) ret+=x%10,x/=10;
	return ret;
}
double cal(ll x){
	return x*1.0/ss(x); 
}
int main(){
	scanf("%d",&k);
	ll t=1,ans=0;
	for (int i=1,j=1;i<=k;i++,j++){
		while (cal(ans+t*10ll)<cal(ans+t)) t=t*10ll;
		ans+=t;
		printf("%lld\n",ans);
	}
}