// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;

	cout << (a*b*c)/(2*max(a,max(b,c)));

	return 0;
}
