#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define be(v) (v).begin(), (v).end()

int main() {
	vint a(3);
	rep(i,3) cin >> a[i];
	sort(be(a));
	int ans=0;
	ans+=abs(a[1]-a[0]);
	ans+=abs(a[2]-a[1]);
	cout << ans << endl;
}