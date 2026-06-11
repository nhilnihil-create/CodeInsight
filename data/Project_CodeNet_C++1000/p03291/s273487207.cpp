#include<algorithm>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
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

	long dp[100009][5] = {};//どこまで走査して何文字照合させたか。
	dp[0][0] = 1;


	for (int i = 1; i <= slen; i++) {
		
		for (int j = 0; j <= 3; j++) dp[i][j] = dp[i - 1][j];
		
        for(int j = 0; j <= 3; j++) if (S[i - 1] == '?') dp[i][j] *= 3;
        //?にAを代入しようが、?にBCを代入しようが「状態そのまま」の組み合わせに影響しない
        
		if (S[i - 1] == 'A' || S[i - 1] == '?') dp[i][1] += dp[i - 1][0];
		if (S[i - 1] == 'B' || S[i - 1] == '?') dp[i][2] += dp[i - 1][1];
		if (S[i - 1] == 'C' || S[i - 1] == '?') dp[i][3] += dp[i - 1][2];
        
        for(int j = 0; j <= 3; j++) dp[i][j] %= mod;
	}

	cout << dp[slen][3] << endl;

}