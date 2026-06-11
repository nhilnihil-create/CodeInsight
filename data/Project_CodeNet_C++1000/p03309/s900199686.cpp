#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<tuple>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i] -= i + 1;
	}
	sort(a.begin(), a.end());
	int mid = a[n / 2];
	ll ans = 0;
	rep(i, n) {
      ans += abs(a[i] - mid);
    }
	cout << ans << endl;
}
