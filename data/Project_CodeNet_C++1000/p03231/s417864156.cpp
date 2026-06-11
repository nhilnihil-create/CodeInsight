#include <iostream>
#include <sstream>
#include <stdio.h>
//#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))

using namespace std;
int GCD(lli a, lli b) {
	lli x = more(a, b);
	lli y = less(a, b);
	lli r = x % y;
	while (r > 0) {
		x = y;
		y = r;
		r = x % y;
	}

	return y;
}

int main(void)
{
	lli N, M; cin >> N >> M;
	string S, T; cin >> S >> T;
	int gcd = GCD(N, M);
	lli ans = (lli)N * M / gcd;
	int alpha = N / gcd, beta = M / gcd;
	rep(i, 0, gcd) {
		if (S[alpha * i] != T[beta * i]) {
			ans = -1;
			break;
		}
	}


	cout << ans << endl;

	return 0;
}
