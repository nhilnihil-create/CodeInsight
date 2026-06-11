#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k; cin >> a >> b >> k;
	int k1 = k, i = a;
	for (i; k1-- && i <= b; ++i)
		cout << i << "\n";
	int s = b - k + 1;
	s = max(s, i);
	for (s; s <= b; ++s)
		cout << s << "\n";
	return 0;
}