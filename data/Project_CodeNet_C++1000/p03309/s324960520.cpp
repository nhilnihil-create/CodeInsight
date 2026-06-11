#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll N;
ll A[200005];


ll calc(ll base){

	ll ret = 0;
	for(ll i = 1; i <= N; i++){

		ret += abs(A[i]-base);
	}
	return ret;
}


int main(){

	scanf("%lld",&N);

	ll sum = 0;

	for(int i = 1; i <= N; i++){

		scanf("%lld",&A[i]);
		A[i] -= i;
		sum += A[i];
	}

	ll L = -BIG_NUM,R = BIG_NUM;
	ll ans = HUGE_NUM;

	for(int loop = 0; loop < 100; loop++){

		ll mid1 = (2*L+R)/3;
		ll mid2 = (L+2*R)/3;

		ll value1 = calc(mid1);
		ll value2 = calc(mid2);
		ans = min(ans,min(value1,value2));

		if(value1 <= value2){

			R = mid2;

		}else{

			L = mid1;
		}
	}

	printf("%lld\n",ans);

	return 0;
}
