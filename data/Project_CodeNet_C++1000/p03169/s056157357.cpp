#include <bits/stdc++.h> 
using namespace std; 
#define for_(i, s, e) for (int i = s; i < e; i++)
#define for__(i, s, e) for (ll i = s; i < e; i++)
#define SSTR(x) static_cast<std::ostringstream&>((std::ostringstream() << std::dec << x)).str()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define endl '\n'

vector<vector<vector<double>>> dp;
int n; double N;

double solve(int a, int b, int c) {
	if (dp[a][b][c] != -1) return dp[a][b][c];
	if (a+b+c == 0) return 0;
	
	int d = n-a-b-c;
	double ans = 0;	
	if (a) ans += (1 + solve(a-1, b, c)) * a;
	if (b) ans += (1 + solve(a+1, b-1, c)) * b;
	if (c) ans += (1 + solve(a, b+1, c-1)) * c;
	if (d) ans = (ans + d) / (N - d);
	else ans /= N;
	
	dp[a][b][c] = ans;
	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	N = n;
	dp.resize(n+1, vector<vector<double>> (n+1, vector<double> (n+1, -1)));
	
	vi freq(3);
	for_(i, 0, n) {
		int k; cin >> k;
		freq[k-1] += 1;
	}
	
	cout << setprecision(10) << fixed << solve(freq[0], freq[1], freq[2]) << endl;

	return 0;
}
