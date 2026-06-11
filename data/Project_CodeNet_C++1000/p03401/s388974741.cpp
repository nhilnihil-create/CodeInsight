#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n + 2);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += abs(a[i] - a[i - 1]);
	}
	sum += abs(a[n + 1] - a[n]);

	for (int i = 1; i <= n; i++) {
		cout << sum - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]) + abs(a[i + 1] - a[i - 1]) << endl;
	}


	return 0;
}