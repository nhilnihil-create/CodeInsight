#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

int Q;

int main() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		ll A, B;
		cin >> A >> B;
		if (A == B) {
			cout << (A - 1) * 2 << endl;
		}
		else {
			ll root = sqrtl(A * B - 1);
			ll ans = root * 2 - 1;
			if ((A * B - 1) / root == root)ans--;
			cout << ans << endl;
		}

	}
	return 0;
}
