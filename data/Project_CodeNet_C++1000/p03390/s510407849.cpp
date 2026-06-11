#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int calc(int a, int b) {
	if (a==b) return (a-1)*2;
	if (a>b) swap(a, b);
	
	int res = a-1;
	long long int m = 1LL*a*b-1;
	/*long long int lo = a+2, hi = m, pos;
	while(lo<=hi) {
		long long int mi = (lo+hi)/2;
		if (m/mi == m/(mi-1) || mi>a+2 && m/(mi-1)==m/(mi-2)) {
			pos = mi;
			hi=mi-1;
		} else lo=mi+1;
	}
	printf("- %d\n", pos);
	return res + pos-1-a + m/pos-1;*/
	long long int it = a+1, y=m/it, x;
	long long ran = sqrt(m-1);
	if (ran > it) {
		res += ran-1-it; it=ran-1;
	}
	do {
		res++;
		it++;
		x=y; y = m/it;
	} while (y!=x);
	//printf("- %d\n", it-ran);
	return res + y-1;
}

int main() {
	int q, a, b;
	for(scanf("%d", &q); q--;) {
		scanf("%d%d", &a, &b);
		printf("%d\n", calc(a, b));
	}
	
	return 0;
}