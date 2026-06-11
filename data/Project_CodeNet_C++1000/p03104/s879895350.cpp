#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long A, B;
	cin >> A >> B;
	long long D = 1, ans = 0;
	while (D <= B) {
		long long Anum = (A-1) / (D * 2) * D + max(0ll, (A-1) % (D * 2) - (D - 1));
		long long Bnum = B / (D * 2) * D + max(0ll, B % (D * 2) - (D - 1));
		ans += D * ((Bnum - Anum) % 2);
		D *= 2;
	}
	cout << ans << endl;
}
