#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, z, w;
	cin >> n >> z >> w;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int p = abs(w-a[n-1]);
	int q = -1;
	if(n >= 2) q = abs(a[n-2]-a[n-1]);
	int ans = max(p, q);
	cout << ans << endl;
	return 0;
}