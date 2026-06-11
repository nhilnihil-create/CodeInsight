# include <bits/stdc++.h>
 
using namespace std;

int main() {
	int n;
	cin >> n;
	vector < int > a(n + 2);
	long long total = 0;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
	}
	for ( int i = 1; i <= n + 1; i++ ) {
		total += abs( a[i - 1] - a[i] );
	}
	for ( int i = 1; i <= n; i++ ) {
		long long t = total;
		t -= abs( a[i - 1] - a[i] );
		t -= abs( a[i + 1] - a[i] );
		t += abs( a[i - 1] - a[i + 1] );
		cout << t << '\n';
	}
}