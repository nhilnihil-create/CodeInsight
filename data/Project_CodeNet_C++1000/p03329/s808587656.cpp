#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int  n;
	cin >> n;

	int res = n;
	int counter;
	for (int i = 0; i <= n; i++) {
		counter = 0;
		int t = i;
		while (t > 0) {
			counter += t % 6;
			t = t / 6;
		}
		t = n - i;
		while (t > 0) {
			counter += t % 9;
			t = t / 9;
		}
		res = min(res, counter);
	}
	cout << res << endl;

	return 0;
}