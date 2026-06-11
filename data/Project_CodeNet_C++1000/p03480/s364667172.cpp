#include<algorithm>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<time.h>
#include<tuple>
#include<utility>
#include<vector>

using namespace std;
const long mod = 1000000007;

int main() {

	string S; cin >> S;
	long slen = S.length();
	long res = slen;

	for (long i = 0; i < slen - 1; i++) {
		if (S[i] != S[i + 1]) res = min(res, max(i + 1, slen - i - 1));
	}

	cout << res << endl;
}