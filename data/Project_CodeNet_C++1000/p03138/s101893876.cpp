#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.second < secondElof.second;
}
//**Snippetリスト**//
//rep, vin, all//
//gcdlcm, isPrime, eratos, modinv, bitSearch, bitList, dfs, bfs, dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l, m, n; ll N, M, K, H, W, L;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 0;
vl flag, color; vll path; vl D;
//***********//
vl bitList(ll n, ll k, ll f) {
	vl bitList(k);
	for (ll i = 0; i < k; i++) {
		bitList[i] = f % n;
		f /= n;
	}
	return bitList;
}
int main() {
	cin >> N >> K;
	vl one(48);
	for (j = 0; j < 48; j++) {
		one[j] = 0;
	}
	for (i = 0; i < N; i++) {
		ll a;
		cin >> a;
		vl B = bitList(2, 48, a);
		for (j = 0; j < 48; j++) {
			if (B[j]) one[j]++;
		}
	}
	//デフォルトでは「1以上N以下で0でない数字がちょうどK個ある」の桁DP
	vl P = bitList(2, 48, K);

	// dp[i][smaller][j]
	// 今調べている桁をi, 未満フラグをsmaller, 0が出た回数をjとする
	vector<vl> dp(49, vl(2, 0));
	// 0桁目は便宜上0であると考える
	// 0桁目は0しかありえないがこれはsmallerが確定していないのでsmaller=0しかありえない
	// 結局dp[0][0][0]=1, それ以外は全て0で初期化すればよい
	reverse(P.begin(), P.end());
	reverse(one.begin(), one.end());
	for (i = 0; i < 49; i++) {
		for (j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for (i = 0; i < 48; i++) {
		//cout << P[i] << " ";
	}
	//cout << endl;
	for (i = 0; i < 48; i++) {
		//cout << one[i] << " ";
	}
	//cout << endl;
	for (i = 0; i < 48; i++) {
		for (ll smaller = 0; smaller < 2; smaller++) {
			if (dp[i][smaller] == -1) continue;
			ll X = pow(2, 47 - i);
			//0を選んだ場合
			dp[i + 1][smaller ||P[i]] = max(dp[i + 1][smaller || P[i]], dp[i][smaller] + X * one[i]);
			//1を選んだ場合
			if(smaller) dp[i + 1][1] = max(dp[i + 1][1], dp[i][smaller] + X * (N-one[i]));
			else if(P[i]) dp[i + 1][0] = max(dp[i + 1][0], dp[i][smaller] + X * (N - one[i]));
		}
	}
	// [smaller || x < A[i]]は以下の寄与条件を反映させたものである。
	// smaller=0 から smaller=0 → x = A[i] のとき寄与
	// smaller=0 から smaller=1 → x < A[i] のとき寄与
	// smaller = 1 から smaller = 0 → 常に寄与なし
	// smaller=1 から smaller=1 → 常に寄与
	// [j + (x > 0)]は以下の寄与条件を反映させたものである。(但しj==Kのときのみ例外処理アリ)
	// j=p から j=p → x=0のとき寄与
	// j=p から j=p+1 → x!=0のとき寄与
	for (i = 0; i <= 48; i++) {
		//cout << dp[i][0] << " " << dp[i][1] << endl;
	}
	cout << max(dp[48][0],dp[48][1]);
}
	
