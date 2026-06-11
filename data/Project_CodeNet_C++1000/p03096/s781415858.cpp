#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
#include<iomanip>
#include<tuple>
#include<stack>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;

const ll MOD_CONST = 1000000007;
//const ll MOD_CONST = 998244353;


const int INF = 1000000000;
//const ll INF = 1000000000000000000;



int main() {
	int n;
	cin >> n;
	vector<int> c(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}



	vector<int> dp(n + 1);
	map<int, ll> s;
	dp[0] = 1;
	s[c[1]] = 1;
	for (int i = 1; i <= n; i++) {
		/*for (int j = 0; j <= i; j++) {
			if(c[j] != c[i] && c[j + 1] == c[i])
			dp[i] += dp[j];
		}
		*/
		dp[i] = s[c[i]];

		if (i < n && c[i] != c[i + 1]) {
			s[c[i + 1]] += dp[i];
			s[c[i + 1]] %= MOD_CONST;
		}

	}

	cout << dp[n] << endl;

}

