#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	int ans;
	if (a <= 5) ans = 0;
	else if (13 <= a) ans = b;
	else ans = b / 2;
	cout << ans << endl;
	return 0;
}