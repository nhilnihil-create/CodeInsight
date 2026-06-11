#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

ll dp[100010];
int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < 100010; i++) dp[i] = INF;
	dp[0] = 0;
	for(int i = 0; i < N + 5; i++)
	{
		for(int six = 1; i + six <= N; six *= 6)
		{
			chmin(dp[i + six],dp[i] + 1);
		}
		for(int nine = 1; i+ nine <= N; nine *= 9)
		{
			chmin(dp[i + nine],dp[i] + 1);
		}
		// chmin(dp[i + 1],dp[i] + 1);
	}
	cout << dp[N] << endl;
}