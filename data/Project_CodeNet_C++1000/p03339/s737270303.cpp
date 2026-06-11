#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>
//#include<bits/stdc++.h>

using namespace std;
long long MOD = 1000000007LL;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N;
	string s;
	cin >> N;
	cin >> s;

	map<int, int> dp;
	for (int i = 1; i < N; ++i) {
		if (s[i] == 'W') {
			++dp[0];
		}
	}


	for (int i = 1; i < N; ++i) {
		dp[i] = dp[i - 1];
		if (s[i - 1] == 'E')++dp[i];
		if (s[i] == 'W')--dp[i];
	}

	int ans = N;
	for(auto i = dp.begin(); i != dp.end(); ++i){
		ans = min(ans, N - i->second - 1);
	}

	cout << ans << endl;
	return 0;
}