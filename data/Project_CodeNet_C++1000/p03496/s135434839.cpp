#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;

template<class T>bool chmax(T &a, const T &b) { if( a < b ) { a = b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if( b < a ) { a = b; return 1; } return 0;}

#ifdef LOCAL
	#define eprintf(...) printf(__VA_ARGS__)
#else 
	#define eprintf(...) 1
#endif

#define ROUNDUP(a, b) 		( ((a) + ((b) - 1) ) / b)
#define SET_ZERO(a)	 		( memset((a), 0, sizeof(a)))
#define SET_NUM_ARRAY(a,b)	( memset((a), b, sizeof(a)))

int main() {
	int N;
	scanf("%d", &N);
	int a[50];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	bool trade[50];
	bool pos = true;
	SET_ZERO(trade);
	
	int *maxp = max_element(a, a+N);
	int *minp = min_element(a, a+N);
	int basei = (abs(*maxp) < abs(*minp))?minp-a:maxp-a;
	int base = a[basei];
	
	for (int i = 0; i < N; i++) {
		a[i] += base;
	}
	if (a[0] < 0 || a[1] < 0) pos = false;
	if (pos) {
		for (int i = 1; i < N; i++) {
			if (a[i-1] > a[i]) {
				cnt++;
				a[i] += a[i-1];
				trade[i] = true;
			}
		}
	} else {
		for (int i = N-2; i >= 0; i--) {
			if (a[i] > a[i+1]) {
				cnt++;
				a[i] += a[i+1];
				trade[i] = true;
			}
		}
	}

	printf("%d \n", cnt + N);	
	for (int i = 0; i < N; i++) {
		if (i != basei) printf("%d %d\n", basei+1, i+1);
	}
	printf("%d %d\n", basei+1, basei+1);
	if (pos) {
		for (int i = 0; i < N; i++) {
			if (trade[i]) printf("%d %d\n", i-1+1, i+1);
		}
	} else {
		for (int i = N-1; i >= 0; i--) {
			if (trade[i]) printf("%d %d\n", i+1+1, i+1);
		}
	}
	return 0;
}
