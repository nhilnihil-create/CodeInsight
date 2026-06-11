#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;

int two(int n) {
	int cnt = 0;
	int m = n;
	for (int i = 0; i < m; i++) {
		if (n % 2 != 0)return cnt;
		else {
			cnt++;
			n = n / 2;
		}
	}
	return cnt;
}

int main(){
	int n;
	int ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	for (int i = 0; i < n; i++) {
		ans = ans + two(a.at(i));
	}
	cout << ans << endl;


	return 0;
}
