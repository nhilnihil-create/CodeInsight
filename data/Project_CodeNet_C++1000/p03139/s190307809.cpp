#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(10)





void solve() {

	int n, a, b;
	cin >> n >> a >> b;
	cout << min(a, b) << " ";
	if(a + b > n) {
		cout << a + b - n << "\n";
	}
	else {
		cout << 0 << "\n";
	}
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();

	return 0;
}