#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cassert>
#include <stack> 

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define BASE 77747
#define PI acos(-1.0)
#define MAXLEN 29

typedef std::pair <int, int> pii;
typedef long long ll;
typedef std::vector <ll> vll;

using namespace std;


int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	ll ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		vector <char> a, b;
		ll dp[19][19];
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = 0; 
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) 
			if (mask & (1 << i)) a.push_back(str[i]);
			else b.push_back(str[i]);
		int lena = a.size(), lenb = b.size();
		


		for (int i = 1; i <= n; i++) { 
			for (int j = 0; j < i; j++) {
				int f = j;
				int s = i - 1 - j;
				if (s > lena) continue;
				if (f < b.size() && b[f] == str[2 * n - i]) 
					dp[i][f + 1] += dp[i - 1][f];
				if (s < a.size() && a[s] == str[2 * n - i]) 
					dp[i][f] += dp[i - 1][f];
			}
		}
		ans += dp[n][b.size()];
	}
	cout << ans << endl;
	return 0;
}
