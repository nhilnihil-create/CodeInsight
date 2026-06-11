#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	string s; cin >> s;

	for (int i = 0; i < 3; i++) {
		if (s[i] == '1') {
			cout << '9';
		}else if (s[i] == '9') {
			cout << '1';
		}else {
			cout << s[i];
		}
	}
	cout << endl;
	return 0;
}
