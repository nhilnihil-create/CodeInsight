#include <iostream>

using namespace std;

int main()
{
	int cnt[4] = {};
	int a, b;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;

		cnt[a - 1]++;
		cnt[b - 1]++;
	}

	for (int i = 0; i < 4; i++) {
		if (cnt[i] != 1 && cnt[i] != 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}