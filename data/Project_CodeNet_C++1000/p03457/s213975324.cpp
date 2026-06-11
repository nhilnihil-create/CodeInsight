#include<bits/stdc++.h>
using namespace std;
int dist(int a, int b, int c, int d) {
	return abs(a-c)+abs(b-d);
}
int main () {
	long long n;
	cin >> n;
	int t[100000];
	int x[100000];
	int y[100000];
	t[0] = 0;
	x[0] = 0;
	y[0] = 0;
	for (int i=1; i<=n; i++) {
		cin >> t[i] >> x[i] >> y[i];
		int a, b, c;
		a = t[i] - t[i-1];
		b = dist(x[i], y[i], x[i-1], y[i-1]);
		if (a%b!=0) {cout << "No"; return 0;}
	}
	cout << "Yes";
	return 0;
}