#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int dif = b - a;

	int h = 0;
	for (int ii = 1; ii < dif; ++ii){
		h += ii;
	}

	cout << h - a << "\n";

	return 0;
}
