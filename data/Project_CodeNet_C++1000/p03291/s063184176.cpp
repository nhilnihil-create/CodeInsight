#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	string s;
	cin >> s;

	int n = s.size();
	vector<vector<ll>> dp(n+1,vector<ll>(4,0));
	dp[0][0] = 1;

	for(int i = 0;i < n;i++){
		for(int j = 0;j < 4;j++){
			dp[i+1][j] += dp[i][j] * (s[i] == '?' ? 3LL : 1LL);
			dp[i+1][j] %= MOD;
		}
		if(s[i] == 'A' || s[i] == '?'){
			dp[i+1][1] += dp[i][0];
			dp[i+1][1] %= MOD;
		}
		if(s[i] == 'B' || s[i] == '?'){
			dp[i+1][2] += dp[i][1];
			dp[i+1][2] %= MOD;
		}
		if(s[i] == 'C' || s[i] == '?'){
			dp[i+1][3] += dp[i][2];
			dp[i+1][3] %= MOD;
		}
	}

	cout << dp[n][3] << endl;
}
