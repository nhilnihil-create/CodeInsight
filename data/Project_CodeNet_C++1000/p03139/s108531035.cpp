#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int ma = min(a, b);
	int mi = max(0, a + b - n);
	cout << ma << " " << mi << endl;
}