#include<cstdio>

using namespace std;

typedef long long LL;

int k;

double S(LL x){
	double res = 0;
	while(x){
		res += x % 10;
		x /= 10;
	}
	return res;
}

LL f(LL x){
	double mn = x / S(x);
	LL mark = x;
	for(LL d = 1; d <= x; d *= 10){
		LL t = x / d * d + d * 10 - 1;
		double tmp = t / S(t);
		if(tmp < mn){
			mn = tmp;
			mark = t;
		}
	}
	return mark;
}

int main(){
	scanf("%d", &k);
	LL now = 1;
	while(k--){
		printf("%lld\n", now);
		now = f(now+1);
	}
	return 0;
}