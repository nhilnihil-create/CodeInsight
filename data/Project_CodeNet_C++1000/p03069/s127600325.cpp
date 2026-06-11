#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// Tenka1 Programmer Beginner Contest 2019-C, 946, 
	int n;
	string s;
	cin >> n >> s;
	vector<int> wsum(n + 1, 0), bsum(n + 1, 0);
	bsum[0] = 0;
	wsum.back() = 0;
	int ans = iINF;
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] == '#') bsum[i] = bsum[i - 1] + 1;
		else bsum[i] = bsum[i - 1];
		
		if (s[n - i] == '.') wsum[n - i] = wsum[n + 1 - i] + 1;
		else wsum[n - i] = wsum[n + 1 - i];
}
	rep(i, n + 1) {
		ans = min(ans, wsum[i] + bsum[i]);
	}
	cout << ans << endl;
	return 0;
}