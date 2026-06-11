#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3+10;
const int mod = 1e9+7;

int n;
long long int dp[maxn], psum[maxn];
string s;

int main(){
	cin >> n;
	cin >> s;
	for (int i = 1; i <= n; i++){
		psum[i] = 1;
	}

	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= i; j++){
			if (s[i-2] == '>')
				dp[j] = (psum[n] - psum[j-1]) % mod;
			else 
				dp[j] = psum[j-1];
		}

		for (int j = 1; j <= n; j++)
			psum[j] = (psum[j-1] + dp[j]) % mod;
	}

	cout << ((psum[n] % mod) + mod) % mod << endl;
	return 0;
}
