#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

ll dp[100001][4];


int main(){
	string s;
	cin >> s;

	dp[0][0] = 1;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '?'){
			for (int j = 0; j < 4; j++){
				dp[i+1][j] += (dp[i][j]*3)%MOD;
				dp[i+1][j] %= MOD;
			}
		}else{
			for (int j = 0; j < 4; j++){
				dp[i+1][j] += dp[i][j];
				dp[i+1][j] %= MOD;
			}
		}
		if (s[i] == 'A' || s[i] == '?'){
			dp[i+1][1] += dp[i][0];
			dp[i+1][1] %= MOD;
		}
		if (s[i] == 'B' || s[i] == '?'){
			dp[i+1][2] += dp[i][1];
			dp[i+1][2] %= MOD;
		}
		if (s[i] == 'C' || s[i] == '?'){
			dp[i+1][3] += dp[i][2];
			dp[i+1][3] %= MOD;
		}
	}

	cout << dp[s.length()][3]%MOD << endl;
	return 0;
}