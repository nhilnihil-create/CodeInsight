#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,n) for(int i = 0;i < (int)(n);i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int MAX_BANK = 100010;

int main() {
	ll dp[MAX_BANK];	//引き出す最大の金額より多めに
	rep(i, MAX_BANK)dp[i] = INF;
	dp[0] = 0;
	//i + out6円は、引き出すのに　dp[i]+1回かかるか、dp[i]回である
	// ex) 1円は、引き出すのに0円 + (1円) * 1回かかる　dp[1] = 1
	//2円は引き出すのに1円+(1円)*1回かかる dp[2] = 2
	//6円は引き出すのに5円 + (1円) * 1回かかる dp[6] = 6
	//6円は引き出すのに0円 + (6円) * 1回かかる　dp[6] = 1
	for (int i = 0; i < MAX_BANK; i++) {
		for (int out6 = 1; i + out6 <= MAX_BANK; out6 *= 6) {
			dp[i + out6] = min(dp[i + out6], dp[i] + 1);
		}
		for (int out9 = 1; i + out9 <= MAX_BANK; out9 *= 9) {
			dp[i + out9] = min(dp[i + out9], dp[i] + 1);
		}
	}
	int n;
	cin >> n;
	cout << dp[n] << endl;
	return 0;
}
