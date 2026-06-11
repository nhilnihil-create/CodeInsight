#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	sort(S.begin(), S.end());
	string ans = "Yes";
	char c;
	for (int i = 0; i < 3; i++) {
		if (S[i] == c) {
			ans = "No";
			break;
		}
		c = S[i];
	}
	cout << ans << "\n";

	return 0;
}
