#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int d; cin >> d;
	string  ans;
	if (d == 25) ans = "Christmas";
	if (d == 24) ans = "Christmas Eve";
	if (d == 23) ans = "Christmas Eve Eve";
	if (d == 22) ans = "Christmas Eve Eve Eve";
	cout << ans << endl;
	return 0;
}