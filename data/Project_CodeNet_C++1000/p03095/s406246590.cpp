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
	string S; cin >> S;
	map<char, int> cnt;
	rep(i, 0, S.size())cnt[S[i]]++;
	lli ans = 1;
	for (map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
		ans = (ans * ((lli)it->second + 1)) % MOD;
	ans--;
	cout << ans << endl;

	return 0;
}