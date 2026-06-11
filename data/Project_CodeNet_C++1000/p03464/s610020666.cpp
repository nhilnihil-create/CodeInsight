#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
typedef long long ll;

int main() {
	int k;
	cin >> k;
	vector<int> a(k);
	rep(i,k) cin >> a[i];
	reverse(a.begin(), a.end());
	ll l = 2;
	ll r = 3;
	rep(i,k) {
		l = dup(l, a[i]) * a[i];
		r = dup(r, a[i]) * a[i];
		if (r - l <= 1) {	
			cout << -1 << endl;
			return 0;
		}
	}
	cout << l << " " << r-1 << endl;
}