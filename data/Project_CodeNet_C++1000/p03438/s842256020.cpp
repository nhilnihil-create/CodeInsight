#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum -= a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sum += b[i];
	}

	long long asum = 0, bsum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			asum += a[i] - b[i];
		} else if (a[i] < b[i]) {
			bsum += (b[i] - a[i] + 1) / 2;
		}
	}
	
	if (asum > sum || bsum > sum) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}

	return 0;
}