#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 3) cout << "2 3 25\n";
	else if (n % 2) {
		int arr[] = {12, 2, 10, 3, 9, 4, 8, 6};
		for (int i = 0; i < n; i++) {
			cout << arr[i % 8] + 12 * (i / 8) << " ";
		}
		cout << endl;
	} else {
		int arr[] = {2, 10, 3, 9, 4, 8, 6, 12};
		for (int i = 0; i < n; i++) {
			cout << arr[i % 8] + 12 * (i / 8) << " ";
		}
		cout << endl;
	}
	return 0;
}