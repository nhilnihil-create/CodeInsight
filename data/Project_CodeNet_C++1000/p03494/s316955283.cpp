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
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	
	for (int i = 0; i < n; i++) {
		b.at(i) = two(a.at(i));
	}
	sort(b.begin(), b.end());
	cout << b.at(0) << endl;
	return 0;
}