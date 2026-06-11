#include <iostream>
using namespace std;
int main(void) {
	long long A, B, C;
	cin >> A >> B >> C;
	long long ans = 0;
	long long eaten = min(B, C);
	C -= eaten;
	B -= eaten;
	ans += eaten * 2;
	
	eaten = min(C, A);
	C -= eaten;
	A -= eaten;
	ans += eaten;

	ans += B;

	if (C > 0) ++ans;

	cout << ans << endl;
	return 0;
}