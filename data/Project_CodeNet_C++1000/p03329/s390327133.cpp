#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmin (T& a, T b) {if (a > b) {a = b; return true;} return false;}

long long INF = 1LL << 60;
long long dp[110000];
int p[] = {6,9};
int N;

int main() {
	cin >> N;
	
	rep(i, 110000) dp[i] = INF;
	dp[0] = 0;

	int d;
	rep(i, N+1) {
		if (i != 0) chmin(dp[i], dp[i-1]+1);
		rep(j, 2) {
			d = p[j];
			while (i - d >= 0) {
				chmin(dp[i], dp[i-d]+1);
				d *= p[j];
			}
		}
		// cout << i << ": " << dp[i] << endl;
	}
	cout << dp[N] << endl;
}