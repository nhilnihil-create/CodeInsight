#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef  long long ll;
int gcd(int f , int s){if(s==0)return f;else return gcd(s,f%s);}
int const N = 1000006;
ll const M = 998244353;
long double const ep = .000000000000000001;
ll a , k , arr[N] , cul[N];
ll test(ll y){
	ll re = y * k;
	int p = a;
	re += 5 * (cul[p] - cul[p-y]);
	p -= y;
	for(int i = 5 ; i < 10000000 ; i+=2){
		if(y >= p){
			re += i * cul[p];
			if(re < 0)return 1e18;
			return re;
		}else{
			re += i * (cul[p] - cul[p-y]);
			p -= y;
		}
	}
}
int main() {
	
	scanf("%d%d",&a , &k);
	for(int i = 1 ; i <= a ; i++)scanf("%lld" , arr+i);
	for(int i = 1 ; i <= a ; i++)cul[i] = cul[i-1] + arr[i];
	ll ans = 1e18;
	for(int i = 1 ; i <= a ; i++){
		ans = min(ans , test(i));
	}
	printf("%lld\n", ans + a * k);
	return 0;	
}