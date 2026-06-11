#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int x;
	cin >> x;
	if (x==1) {
		cout << 1 << endl;
		return 0;
	}
	//vector<int> beki;
	int b, p;
	int ans = 0;
	for (int i = 2; i < 32; i++)
	{
		int j = 2;
		while(pow(i, j) <= x) {
			ans = max(ans, int(pow(i, j)+0.5));
			j++;
		}
	}
	cout << ans << endl;
	//sort(beki.begin(), beki.end(), greater<int>());
	//cout << beki[0] << endl;
	return 0;
}