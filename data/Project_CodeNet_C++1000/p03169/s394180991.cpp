#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

double dp[901][501][303];

signed main()
{
	IO_OP;
	
	int n, sum = 0;
	cin >> n;
	int cnt[3] = {};
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
		cnt[x - 1]++;
	}
	for(int k = 0; k * 3 <= sum; k++)
		for(int j = 0; k * 3 + j * 2 <= sum; j++)
			for(int i = 0; i + k * 3 + j * 2 <= sum; i++) {
				if(i == 0 && j == 0 && k == 0) {
					dp[i][j][k] = 0;
				} else {
					int left = n - i - j - k;
					double c = 1 - (double) left / n;
					dp[i][j][k] = (1 + (i ? dp[i - 1][j][k] : 0.) * i / n +
								   (j ? dp[i + 1][j - 1][k] : 0.) * j / n +
								   (k ? dp[i][j + 1][k - 1] : 0.) * k / n) / c;
				}
			}

	
	cout << fixed << setprecision(10) << dp[cnt[0]][cnt[1]][cnt[2]] << endl;


}

