#include <iostream>
#include <string>

using namespace std;

int solve(const string& s)
{
	int l = 0;
	int r = s.length() - 1;

	int ans = 0;
	while (l < r) {
		if (s[l] == s[r]) {
			++l;
			--r;
		}
		else if (s[l] == 'x') {
			++l;
			++ans;
		}
		else if (s[r] == 'x') {
			--r;
			++ans;
		}
		else {
			return -1;
		}
	}
	return ans;
}


int main()
{
	string s;
	cin >> s;
	cout << solve(s) << endl;
}

