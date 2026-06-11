#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	int d = b - a;
	int i = 1;
	int sum = 0;
	while (d--) {
		sum += i;
		i++;
	}
	cout << sum - b << endl;
	return 0;
}