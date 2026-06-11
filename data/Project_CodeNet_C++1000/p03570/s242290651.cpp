#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

string s;
int a[2 * 100000+1], opt[2*100000], dp[1<<26], chara['z'-'a'+1], X['z'-'a'+2];

int main() {
	cin >> s;
	//初期化
	for (int i = 0; i < 26; i++) {
		chara[i] = 1 << i;
		X[i + 1] = 1 << i;
	}
	for (int i = 0; i < 1 << 26; i++)dp[i] = INT32_MAX;
	dp[0] = 0;
	for (int i = 0; i < s.length(); i++)opt[i] = INT32_MAX;

	//aの作成
	for (int i = 0; i < s.length(); i++) {
		a[i+1] = a[i] ^ chara[s[i] - 'a'];
	}

	//分割数を計算
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j <= 26; j++) {
			if(dp[a[i+1]^X[j]] != INT32_MAX)opt[i] = min(opt[i], dp[a[i + 1] ^ X[j]] + 1);
		}
		dp[a[i + 1]] = min(dp[a[i + 1]], opt[i]);
	}

	cout << opt[s.length() - 1] << endl;
}