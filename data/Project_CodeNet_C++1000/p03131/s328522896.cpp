#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
	long long k, a, b;
	cin >> k >> a >> b;

	if (b - a <= 2) {
		cout << k + 1 << endl;
	} else {
		if (a - 1 >= k) {
			cout << k + 1 << endl;
		} else {
			long long now = a;
			k = k - a + 1;

			if (k % 2 == 0) {
				now += (b - a) * (k / 2);
				cout << now << endl;
			} else {
				now += (b - a) * (k / 2);
				cout << now + 1 << endl;
			}
		}
	}
	
	return 0;
}