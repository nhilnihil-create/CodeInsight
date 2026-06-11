#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 100005;

int n;

int main() {

	FAST;

	cin >> n;
	if (n == 1) {
		cout << "Hello World\n";
	}
	else {
		int a, b;
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}