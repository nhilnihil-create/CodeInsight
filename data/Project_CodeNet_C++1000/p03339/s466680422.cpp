#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>sumW(n + 1, 0);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			sumW[i + 1] = sumW[i] + 1;
		}
		else {
			sumW[i + 1] = sumW[i];
		}
	}
	vector<int>sumE(n + 1, 0);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'E') {
			sumE[i + 1] = sumE[i] + 1;
		}
		else {
			sumE[i + 1] = sumE[i];
		}
	}

	int ans = 1e9;
	for (int i = 0; i < n+1; i++) {
		ans = min(ans, (sumW[i] + sumE[n] - sumE[i]) );
		
	}
	cout << ans << endl;
	return 0;
}