#include <iostream>
#include <sstream>
#include <stdio.h>
#define _USE_MATH_DEFINES
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

int main(void)
{
	int N; cin >> N;
	vector<lli> S(N + 1, 0);
	rep(i, 1, N + 1) {
		lli A; cin >> A;
		S[i] = S[i - 1] + A;
	}
	map<lli, lli> cnt;
	rep(i, 0, N + 1)cnt[S[i]]++;
	lli ans = 0;
	for (map<lli, lli>::iterator it = cnt.begin(); it != cnt.end(); it++)
		ans += (it->second) * (it->second - 1) / 2;
	
	cout << ans << endl;

	return 0;
}
