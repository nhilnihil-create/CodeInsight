#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int ans = s.size();
	for (int i = 0; i < s.size()-1; ++i) {
		if (s[i]!=s[i+1]) {
			ans = min(ans, max(i+1, (int)s.size()-i-1));
		}
	}
	cout << ans << endl;
	return 0;
}