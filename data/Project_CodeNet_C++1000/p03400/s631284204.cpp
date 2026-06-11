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

int main(){
	int n, x,d;
	int ans = 0;
	cin >> n >> d >> x;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	for (int i = 0; i < n; i++) {
		b.at(i) =( d -1)/ (a.at(i)) + 1;
	}
	for (int i = 0; i < n; i++) {
		ans += b.at(i);
	}

	cout << ans + x << endl;
	return 0;
}
