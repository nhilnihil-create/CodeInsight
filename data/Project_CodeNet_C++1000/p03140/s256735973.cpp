#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string s, t, u;
	cin >> n >> s >> t >> u;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) {
			if (s[i] != u[i]) {
				ans++;
			}
		}
		else if (s[i] == u[i]) {
			ans++;
		}
		else if (u[i] == t[i]) {
			ans++;
		}
		else {
			ans += 2;
		}
	}
	cout << ans << endl;
	
	return 0;
}