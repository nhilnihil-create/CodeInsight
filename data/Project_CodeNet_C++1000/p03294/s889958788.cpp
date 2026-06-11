#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
int main() {
	int n; cin >> n;
	vint a(n);
	ll ans=0;
	rep(i,n) {
		cin >> a[i];
		ans+=a[i];
	}
	cout << ans-n << endl;
}
