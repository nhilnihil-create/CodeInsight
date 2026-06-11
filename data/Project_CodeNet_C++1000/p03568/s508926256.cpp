#include <iostream>
#include <vector>

using namespace std;

long long mpow(long long a, long long b);

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int ans = 0;
	int s;
	int t;
	for (int i = 0; i < mpow(3, n); i++) {
		s = i;
		t = 1;
		for (int j = 0; j < n; j++) {
			switch (s % 3) {
			case 0:
				t *= a[j] - 1;
				break;
			case 1:
				t *= a[j];
				break;
			case 2:
				t *= a[j] + 1;
				break;
			}
			s /= 3;
		}
		if (t % 2 == 0) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}

long long mpow(long long a, long long b)
{
	long long ans = 1;
	while (b != 0) {
		if ((b & 1) == 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}

	return ans;
}