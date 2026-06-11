#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string s, t;
	int s_size, t_size, N;

	cin >> s >> t;

	sort(s.begin(), s.end());
	sort(t.rbegin(), t.rend());

	if (s < t) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}