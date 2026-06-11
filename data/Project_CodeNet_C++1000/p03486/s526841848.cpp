#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	string s, t;
	cin >> s >> t;
	char mins = 'z', maxt = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		mins = min(mins, s[i]);
	}
	for (int i = 0; i < (int)t.size(); i++) {
		maxt = max(maxt, t[i]);
	}
	if (maxt > mins)
		return printf("Yes\n"), 0;
	else if (mins > maxt)
		return printf("No\n"), 0;
	else {
		if (t.size() > s.size()) {
			sort(s.begin(), s.end());
			sort(t.begin(), t.end());
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] != t[i])
					return printf("No\n"), 0;
			}
			return printf("Yes\n"), 0;
		} else
			return printf("No\n"), 0;
	}
}
