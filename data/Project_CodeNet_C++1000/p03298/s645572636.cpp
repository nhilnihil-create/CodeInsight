#include <iostream>
#include <vector>
using namespace std;

const int N = 20;
int n;

long long dp[N][N];
vector <int> r;
vector <int> b;
string s;

int get(int x, int y) {
	return (x >> y) & 1;
}
long long f(int mask) {
	r.clear();
	b.clear();
	for (int i = 0; i < n; i++) {
		if (get(mask, i))
			r.push_back(i);
		else
			b.push_back(i);
	}
//	cout << 73 << " " << r.size() << " " << b.size() << endl;
	for (int i = 0; i <= n; i++) {
	    for (int j = 0; j <= n; j++) {
	        dp[i][j] = 0;
	    }
	}
	dp[0][0] = 1;
	for (int i = 0; i <= r.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
		 //  cout << i << " " << j << " " << dp[i][j] << endl;
	//		dp[i][j] = 0;
			if (i > 0 && s[r[i - 1]] == s[2 * n - i - j])
	        	dp[i][j] += dp[i - 1][j];
	        
			if (j > 0 && s[b[j - 1]] == s[2 * n - i - j])
				dp[i][j] += dp[i][j - 1];
//			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	
//	cout << mask << " " << dp[(int) r.size()][(int) b.size()] << endl;
	return dp[(int) r.size()][(int) b.size()];
}
int main() {
	cin >> n;
	cin >> s;
	long long ans = 0;
//	for (int i = n; i < 2 * n; i++)
//	    t.push_back(s[i - n]);
	for (int i = 0; i < (1 << n); i++) {
		ans += f(i);
	}
	cout << ans << endl;
	return 0;
}