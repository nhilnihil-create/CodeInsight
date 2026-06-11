#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int a, b;
	cin >> a >> b;
	int ans;
	if ((a + b)%2 == 0) {
		ans = (a + b)/2;
	}
	else{
		ans = (a + b)/2 + 1;
	}
	cout << ans << endl;
	return 0;
}
