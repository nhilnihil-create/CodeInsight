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
#include <string>
#include <cassert>

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define PI acos(-1.0)

typedef std::pair <int, int> pii;
typedef long long ll;
typedef std::vector <ll> vll;

using namespace std;

int dp[1 << 26];
int opt[200001];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	for (int i = 0; i < (1 << 26); i++) dp[i] = -1;
	dp[0] = 0;
	for (int i = 0; i <= str.length(); i++) opt[i] = INF;
	opt[0] = 0;
	int mask = 0;
	for (int i = 0; i < str.length(); i++) {
		mask ^= (1 << (str[i] - 'a'));
		if (dp[mask] != -1) 
			opt[i + 1] = min(opt[i + 1], opt[dp[mask]] + 1);
		for (int j = 0; j < 26; j++) {
			if (dp[mask ^ (1 << j)] != -1) {
				opt[i + 1] = min(opt[i + 1], opt[dp[mask ^ (1 << j)]] + 1);
			}
		}
		if (dp[mask] == -1)
			dp[mask] = i + 1;
		else if (opt[dp[mask]] > opt[i + 1])
			dp[mask] = i + 1;
	}
	cout << opt[str.length()] << endl;
	return 0;
}