#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_string_rotation(void) {
	string s, t;
	string msg = "No";
	cin >> s >> t;

	for (int i = 0; i < s.size(); i++) {
		s = s[s.size() - 1] + s.substr(0, s.size()-1);
		//cout << s << endl;
		if (s == t) {
			msg = "Yes";
			break;
		}
	}

	cout << msg << endl;
}

int main()
{
	b_string_rotation();
    return 0;
}