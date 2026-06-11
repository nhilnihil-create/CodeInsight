#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	ll r,D,x2000;
	scanf("%lld %lld %lld",&r,&D,&x2000);

	ll pre = x2000;
	for(int i = 0; i < 10; i++){

		printf("%lld\n",r*pre-D);
		pre = r*pre-D;
	}

	return 0;
}
