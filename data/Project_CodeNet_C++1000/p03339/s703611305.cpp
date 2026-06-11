#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int>a(n, 0);
	vector<int>sum(n, 0);
	if (s[0] == 'W') {
		a[0] = 1;
		sum[0] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == 'W')a[i] = 1;
		sum[i] += sum[i - 1] + a[i];
	}
	int minNum = n;
	minNum = min(minNum, (n - 1) - (sum[n - 1] - sum[0]));
	minNum = min(minNum, sum[n - 2]);
	for (int i = 1; i < n - 1; i++) {
		int left = (n - 1 - i) - (sum[n - 1] - sum[i]);
		int right = sum[i - 1];
		minNum = min(minNum, left + right);
	}
	cout << minNum << endl;
	return 0;
}