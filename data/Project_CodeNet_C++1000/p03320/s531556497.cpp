#include <cstdio>
using namespace std;
typedef long long ll;
double S(ll n){
	ll t=n;
	int sum=0;
	for(;n;n/=10) sum+=n%10;
	return 1.0*t/sum;
}
int main(){
	ll n;
	scanf("%lld",&n);
	ll cur=0,delta=1;
	while(n--){
		for(;;delta*=10)
			if(S(cur+delta)<=S(cur+delta*10))
				break;
		cur+=delta;
		printf("%lld\n",cur);
	}
	return 0;
}
