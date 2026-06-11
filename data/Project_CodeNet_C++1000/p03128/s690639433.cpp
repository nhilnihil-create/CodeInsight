#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
const int MOD = 1e9+7;
const int MOOD = 998244353;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int use[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[10001];

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];

	sort(a.begin(), a.end(), greater<int>());

	for (int i = 0; i <= 10000; i++) dp[i] = -1;
	dp[0] = 0;

	for (int i = 2; i <= n; i++){
		for (int j = 0; j < m; j++){
			if (i - use[a[j]] >= 0 && dp[i-use[a[j]]] != -1){
				dp[i] = max(dp[i], dp[i-use[a[j]]] + 1);
			}
		}
	}
	int temp = n;
	string ans;
	while (temp != 0){
		for (int i = 0; i < m; i++){
			if (dp[temp-use[a[i]]] + 1 == dp[temp] && temp-use[a[i]] >= 0){
				temp -= use[a[i]];
				ans += to_string(a[i]);
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
