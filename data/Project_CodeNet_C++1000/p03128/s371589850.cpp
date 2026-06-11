#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;



int main() {
	int n, m;
	cin >> n >> m;

	vector<int> cost{ 100,2,5,5,4,5,6,3,7,6 };

	vector<int> a(m);
	
	
	for (int i = 0; i < m;i++) {
		cin >> a[i];
		
	}

	sort(a.begin(), a.end(),greater<int>());

	vector<int> dp(n+1);
	for (int i = 1; i <= n;i++) {
		dp[i] = -100000000;
		for (int j = 0; j < m;j++) {
			if (i >= cost[a[j]]) {
				dp[i] = max(dp[i - cost[a[j]]]+1, dp[i]);
			}
		}
		//cout << dp[i] << endl;
	}


	
	string s;
	for (int i = n; i > 0;) {
		for (int j = 0; j < m;j++) {

			
			if (i >= cost[a[j]] && dp[i-cost[a[j]]] == (dp[i] -1)) {
				s += ('0' + a[j]);
				i -= cost[a[j]];
				
				break;
				
			}
		}
		

	}
	
	cout << s << endl;
}
