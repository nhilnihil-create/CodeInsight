#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int	ans = 1e10;

	auto check = [](int x){
		int num = 0;
		while (x) {
			num += x % 10;
			x /= 10;
		}
		return num;
	};

	for (int i = 1; i < n; i++) {
		int a = check(i), b = check(n - i);
		if (ans > a + b)ans = a + b;	
	}
	cout << ans << endl;

	return 0;
}