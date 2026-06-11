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


int main(void)
{
	lli N; cin >> N;
	vector<int> digits;
	int ans = 0;
	while (N > 0) {
		ans += (N % 10);
		digits.push_back(N % 10);
		N /= 10;
	}
	ans = more(ans, (digits[digits.size() - 1] - 1 + (digits.size() - 1) * 9));
	/*
	for (int i = digits.size() - 1; i >= 1;i--) {
		if (digits[i] > digits[i - 1]) {
			ans = digits[i] - 1;
			ans += (digits.size() - 1) * 9;
			break;
		}
	}
	*/
	cout << ans << endl;

	return 0;
}
