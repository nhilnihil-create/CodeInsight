#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 200000;
ull sum[MAXN + 5];
int main() {
	int N; ull X;
	cin >> N >> X;
	for(int i=1;i<=N;i++) {
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	ull ans = X*N + sum[N]*5;
	for(int i=1;i<N;i++) {
		ull res = X*i;
		if( 2*i >= N )
			res = res + sum[N]*5;
		else {
			ull coef = 7;
			int lst = N - 2*i;
			res = res + (sum[N]-sum[N-2*i])*5;
			while( lst >= i ) {
				res = res + (sum[lst]-sum[lst-i])*coef;
				lst -= i; coef += 2;
			}
			res = res + sum[lst]*coef;
		}
		if( res < ans ) ans = res;
	}
	cout << ans + X*N;
} 