#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int t = 1;
	for (int i = 0; i < m; i++) {
		t *= 2;
	}
	int ans = t * (n - m) * 100;

	t *= m;
	ans += t * 1900;
	cout << ans << endl;

	return 0;
}