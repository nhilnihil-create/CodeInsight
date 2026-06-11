#include <iostream>

using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;

	long long ans = 0;
	long long t = 2;
	while (a <= b) {
		a *= t;
		ans++;
	}
	cout << ans << endl;

	return 0;
}