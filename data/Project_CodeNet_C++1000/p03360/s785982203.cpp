#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int mx = max(a, max(b, c));
    int sum = a + b + c - mx;
    for (int i = 0; i < k; i++) {
		mx *= 2;
	}
	sum += mx;
	cout << sum;
    return 0;
}
