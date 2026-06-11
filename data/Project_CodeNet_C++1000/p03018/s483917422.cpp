#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "afjawe";
	cin >> s;

	long long ans = 0;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i, 1) == "A") {
			cnt++;
		} else if (s.substr(i, 2) == "BC") {
			i++;
			ans += cnt;
		} else {
			cnt = 0;
		}
	}
	cout << ans << endl;

	return 0;
}