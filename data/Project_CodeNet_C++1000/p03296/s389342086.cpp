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
	int N; cin >> N;
	vector<int> A(N); rep(i, 0, N)cin >> A[i];
	int ans = 0, cnt = 1;
	int tmp = A[0];
	rep(i, 1, N) {
		if (A[i] == tmp)cnt++;
		else {
			ans += (cnt / 2);
			cnt = 1;
			tmp = A[i];
		}
		if(i == N - 1)ans += (cnt / 2);
	}
	cout << ans << endl;

	return 0;
}
