#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	int n1 = 0, n2 = 0, n3 = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] <= a) {
			n1++;
		}
		else if (p[i] <= b) {
			n2++;
		}
		else {
			n3++;
		}
	}
	cout << min(n1, min(n2, n3)) << endl;

	return 0;
}