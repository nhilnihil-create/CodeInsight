#include <iostream>

using namespace std;

int main() {
	long long x;
	cin >> x;
	long long y;
	cin >> y;
	long long ans = 0;
	while (x <= y) {
		ans++;
		x *= 2;
	}
	cout<<ans;
	return 0;
}