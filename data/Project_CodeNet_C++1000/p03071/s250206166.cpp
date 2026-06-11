#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	int ans = 0;
	if (A > B) {
		ans += 2 * A - 1;
	}
	else if (A == B) {
		ans += 2 * A;
	}
	else {
		ans += 2 * B - 1;
	}

	cout << ans << endl;
	return 0;
}