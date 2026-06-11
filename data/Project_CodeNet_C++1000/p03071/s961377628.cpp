#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define ll long long
#define be(v) v.begin(), v.end()

int main() {
	int a,b; cin >> a >> b;
	int ans = 0;
	rep(i,2) {
		ans+=max(a,b);
		if(max(a,b)==a) a--;
		else b--;
	}
	cout << ans << endl;
}