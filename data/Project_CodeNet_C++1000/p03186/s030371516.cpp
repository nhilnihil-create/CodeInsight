#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
 
int a, b, c;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> c;
	if (a+b < c) {
		cout << a+2*b+1;
		return 0;
	} else {
		cout << b+c;
		return 0;
	}
}