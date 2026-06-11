#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1005;

int n;
int a[N];

int main() {

	FAST;

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (abs(a - c) <= d || (abs(b - a) <= d && abs(c - b) <= d)) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	return 0;
}