#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string s, t;
	cin >> s >> t;

	bool f = false;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	
	if (s.size() < t.size()) {
		bool b = true;
		//cout << s << endl;
		//cout << t << endl;

		for (int i = 0; i < s.size(); i++) {
			//cout << s.at(i) << endl;
			//cout << count(t.begin(), t.end(), s.at(i)) << endl;
			
			if (count(t.begin(), t.end(), s.at(i)) == 0) {
				//cout << s.at(i) << endl;
				b = false;
				break;
			}
		}

		if (b) f = true;
	}
	//cout << f << endl;

	reverse(t.begin(), t.end());
	if (s < t) f = true;

	cout << (f ? "Yes" : "No") << endl;
}