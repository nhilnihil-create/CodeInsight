#include<iostream>
using namespace std;

int main() {
	int64_t X, Y, ans = 0;
	cin >> X >> Y;

	while (X <= Y) {
		ans++;
		X *= 2;
	}

	cout << ans << endl;
}