//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//#include "sort/bsearch.h"

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

//#include "sort/merge.h"

template<class I, class N=long>
N merge(I a, I ea, I b, I eb, I &c) {
	N inv = 0;
	N n = std::distance(a, ea);
	while (a != ea && b != eb) {
		if (*b < *a) {
			*c++ = *b++;
			inv += n;
		}
		else {
			*c++ = *a++;
			n -= 1;
		}
	}
	while (a != ea) *c++ = *a++;
	while (b != eb) *c++ = *b++;
	return inv;
}


//return reverse pair count
template<class I, class N=long>
N merge_sort(const I &a, const I &e, I tmp) {
	int n = std::distance(a, e);
	if (n<2) return 0;
	auto m = std::next(a, n/2);
	auto t = tmp;
	N left  = merge_sort(a, m, t);
	N right = merge_sort(m, e, t);
	N both  = merge(a, m, m, e, t);
	copy(tmp, t, a);
	return left + right + both;
}

template<class C, class N=long>
N merge_sort(C &a) {
	int n = a.size();
	if (n<2) return 0;
	C t;
	//TODO
	auto i = back_inserter(t);
	return merge_sort(a.ebgin(), a.end(), i);
}
//#include "seq/psum.h"

//b[i] = sum:a[0,i), b can be a-1
template<class I>
void psum_create_z(I a, I e, I b) {
	*b = 0;
	while (a != e) {
		auto x = (*b++) + (*a++);
		*b = x;
	}
}

template<class I>
void psum_create(I a, I e) {
	if (a==e) return;
	auto s = *a++;
	while (a != e) {
		s = s + *a;
		*a++ = s;
	}
}


#define MAXN 100000

int n;
int a[MAXN], b[MAXN+1], c[MAXN+1];

int input() {
	if (scanf("%d", &n) < 0) return 0;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	return 1;
}

void init() {
}

int is_median(int x) {
	for (int i=0; i<n; i++)
		b[i+1] = (a[i]>=x) ? 1: -1;
	//printa(a, n); printa(b+1, n);
	psum_create_z(b+1, b+n+1, b);
	//printa(b, n+1);

	long inv = merge_sort(b+0, b+n+1, c+0);

	/*
	long inv = 0;
	for (int i=0; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (b[i]>b[j]) inv++;
	*/

	long m = long(n)*(n+1)/2;
	long cnt = m-inv;
	int ok = cnt >= (m+1)/2;
	//p(x, 'i', inv, 'c', cnt, 'm', m, ok);
	return ok;
}

long solve() {
	int ma = *max_element(a, a+n), mi = *min_element(a, a+n);
	return bsearch_largest(mi, ma+1, is_median);
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
}

int main() {
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



