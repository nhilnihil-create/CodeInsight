// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9;

signed main(){
	int te;scanf("%lld",&te);
	while(te--){
		int a,b;scanf("%lld%lld",&a,&b);
		if(a>b)swap(a,b);
		if(a==b){printf("%lld\n",2*a-2);continue;}
		if(a+1==b){printf("%lld\n",2*a-2);continue;}
		int c=sqrt(1ll*a*b);
		if(c*c==a*b)--c;
		if(c*(c+1)>=a*b)printf("%lld\n",2*c-2);
		else printf("%lld\n",2*c-1);
	}

	return 0;
}
