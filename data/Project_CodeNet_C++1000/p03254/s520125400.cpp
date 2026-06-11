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
	int n, x;
	int ans = 0;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (x >= a.at(i)) {
			ans++;
			x -= a.at(i);
		}
		
	}
	if (x > 0&&ans==n)ans--;
	cout << ans << endl;
	return 0;
}
