#include <iostream>
#include <cstring>
using namespace std;
#define ll long long

ll dp[405][405], num[405];
ll inf = 1e11;

int main()
{
	ll n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	auto sum = [&](int L, int R) {
		ll s = 0;
		for(int i = L; i <= R; ++i) {
			s += num[i];
		}
		return s;
	};
	for (int j = 0; j < n; ++j) {
		for (int i = j; i >= 0; --i) {
		    if (j == i) {
		    	dp[i][j] = 0;
		    } else {
		    	dp[i][j] = 1e18L + 5;
				ll s = sum(i, j);
				for (int k = i; k < j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s);
				}
		    }
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
