//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//#include "seq/bsearch.h"

//find largest x in [s,t) which check(x) is true
template<class T>
T bsearch_largest(T s, T t, int check(T)) {
	s--;
	while (t-s>1) {
		T m = (s+t)/2;
		if (check(m)) s = m;
		else t = m;
	}
	return s;
}

//find smallest x in [s,t) which check(x) is true
template<class T>
T bsearch_smallest(T s, T t, int check(T)) {
	s--;
	while (t-s>1) {
		T m = (s+t)/2;
		if (check(m)) t = m;
		else s = m;
	}
	return t;
}


#define MAXN 100000

long a, b;

int input() {
	if (scanf("%ld %ld", &a, &b) < 0) return 0;
	return 1;
}

void init() {
}

void maxit(long &r, long sum, long x, long s, long t) {
	long y = sum - x;
	if (x>=s && x<=t) {
		r = max(r, x*y);
	}
}
long maxp(long sum, long s, long t) {
	long r = LONG_MIN;
	if (t<s) return r;
	maxit(r, sum, s, s, t);
	maxit(r, sum, t, s, t);
	long m = sum/2;
	maxit(r, sum, m, s, t);
	maxit(r, sum, m+1, s, t);
	return r;
}
/*
	max: p=i*(s-i)
	i=[1,p): s=x+1
	i=(p,q]: s=x+2
	i=(q,x]: s=x+1
	p,q = a, x+2-b

	1,2,...a-1,a+1.........x-1,x
	x,x-1..........b+1,b-1...2,1
*/
int check(long x) {
	long r, y = x;
	if (a>x) {
		r = maxp(x+1, 1, x);
	}
	else if(b>x) {
		long r1 = maxp(x+1, 1, a-1);
		long r2 = maxp(x+2, a+1, x+1);
		r = max(r1, r2);
	}
	else {
		x++;
		if (a+b < x+1) {
			long p = a, q = x+2-b;
			long r1 = maxp(x+1,1,p-1);
			long r2 = maxp(x+2,p+1,q);
			long r3 = maxp(x+1,q+1,x);
			r = max(max(r1,r2),r3);
		}
		else if(a+b > x+1) {
			long p = x-b, q = a;
			long r1 = maxp(x+1,1,p-1);
			long r2 = maxp(x,p,q-1);
			long r3 = maxp(x+1,q+1,x);
			r = max(max(r1,r2),r3);
		}
		else {
			long p = a;
			long r1 = maxp(x+1,1,p-1);
			long r2 = maxp(x+1,p+1,x);
			r = max(r1, r2);
		}
	}
	//printf("=%ld : %d\n", y, r<a*b);
	return  r < a*b;
}

long solve() {
	if (a>b) swap(a,b);
	return bsearch_largest(1L, min(10000000000L,a*b), check);
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
}

int main() {
	int ca; scanf("%d",&ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



