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
		if (n % 2 == 0) {
			cnt++;
			n = n / 2;
		}
		else return cnt;
		
	}
	return cnt;
}
int main() {
	int n,k;
	int cnt = 0;
	int cnt2 = 0;
	int ans=0;
	cin >> n >> k;
	vector<int> a(n),b(n);

	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		b.at(a.at(i)-1)++;
	}
	for (int i = 0; i < n; i++) {
		if (b.at(i) != 0)cnt++;
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		if (b.at(0) == 0)b.erase(b.begin());
	}
	
	if (cnt <= k)ans = 0;
	else {
		for (int i = 0; i < cnt - k; i++) {
			ans += b.at(i);
		}

	}

	//for (int i = 0; i < b.size(); i++)cout << b.at(i) << endl;
	cout << ans << endl;
	return 0;
}