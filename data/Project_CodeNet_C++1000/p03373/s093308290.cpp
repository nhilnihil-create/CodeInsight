#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<iterator>
#include<complex>
#include<stack>
#include "stdio.h"
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const long long mod_const = 1e9+7;
using MIte = multimap<long, long, greater<long> >::iterator;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	if (A + B <= 2 * C) {
		cout << A * X + B * Y << endl;
	}
	else {
		if (X >= Y) {
			cout << 2 * C * Y + min(A,2*C) * (X - Y) << endl;
		}
		else {
			cout << 2 * C * X + min(B,2*C) * (Y - X) << endl;
		}
	}

	return 0;
}