#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int i = 0, j = s.length() - 1;
	int ans = 0;
	while (i < j) {
		if (s[i] == s[j]) {
			i++;
			j--;
		} else if (s[i] == 'x') {
			ans++;
			i++;
		} else if (s[j] == 'x') {
			ans++;
			j--;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;

	return 0;
}