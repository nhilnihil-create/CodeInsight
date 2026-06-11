#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {
	
	string s,t; cin >> s >> t;

	for (int i = 0; i < s.size() + 1; i++) {
		string tmp = s.substr(s.size() - 1, 1);
		s = tmp + s.substr(0,s.size() - 1);
		if (s == t) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}
