#include <bits/stdc++.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

int main() {
	string s;
	cin >> s;
	int count = 0;

	for (int i = 0; i < 3; i++) {
		if (s.at(i) == '1') {
			count++;
		}
	}
	cout << count << endl;
}