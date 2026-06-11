#include <bits/stdc++.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	int A = 0;
	int B = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) A += a.at(i);
		else B += a.at(i);
	}
	cout << A - B << endl;
}