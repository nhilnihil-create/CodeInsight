#include<cstdio>
#define int long long
int base=1,ans,n;
double calc(int x){
	int res=0,y=x;
	while(x)res+=x%10,x/=10;
	return (1.0*y)/(1.0*res);
}
signed main(){
	scanf("%lld",&n);
	while(n--){
		while(1){
			if(calc(ans+base)>calc(ans+base*10))
				base*=10;
			else break;
		}
		ans+=base;
		printf("%lld\n",ans);
	}
}