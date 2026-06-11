#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int a,b;
	cin >> a >> b;
	int ans = a;
	if (b<a) ans--;
	cout << ans << endl;
	return 0;
}
