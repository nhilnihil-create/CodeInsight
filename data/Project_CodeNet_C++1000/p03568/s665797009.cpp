#include <iostream>
#include <vector>

using namespace std;

int mpow(int a, int b);

int main()
{
	int n, a, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 == 0) {
			t++;
		}
	}
	
	cout << mpow(3, n) - mpow(2, t) << endl;

	return 0;
}

int mpow(int a, int b)
{
	int ans = 1;
	while (b != 0) {
		if ((b & 1) == 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}

	return ans;
}