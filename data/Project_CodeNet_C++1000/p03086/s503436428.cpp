#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		string t = s.substr(i);
		for (int j = 0; j < t.size(); j++) {
			string u = t.substr(0, j + 1);
			int tmp = u.size();
			bool acgt = true;
			for (int k = 0; k < u.size(); k++) {
				if (u[k] == 'A' || u[k] == 'C' || u[k] == 'G' || u[k] == 'T') {}
				else {
					acgt = false;
				}
			}			
			if (acgt) ans = max(ans, tmp);
		}		
	}
	cout << ans << endl;
	return 0;
}