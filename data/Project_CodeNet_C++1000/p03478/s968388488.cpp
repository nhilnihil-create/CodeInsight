#include <iostream>
using namespace std;
int main() {
	int N, A, B, a, b, c, d, e;
	int total = 0;
	cin >> N >> A >> B;
	
	for (int i = 1; i <= N; i++) {
		a = i / 10000;
		b = (i - a * 10000) / 1000;
		c = (i - a * 10000 - b * 1000) / 100;
		d = (i - a * 10000 - b * 1000 - c * 100) / 10;
		e = i - a * 10000 - b * 1000 - c * 100 - d * 10;
		if (A <= (a + b + c + d + e) && (a + b + c + d + e) <= B)
			total = total + i;
	}
	cout << total;
}