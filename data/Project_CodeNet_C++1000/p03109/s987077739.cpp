#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	string s; cin >> s;

	string t = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '/') {
			t += s[i];	
		}
	}

	int n = stoi(t);

	if (n > 20190430) {
		cout << "TBD" << endl;	
	}else {
		cout << "Heisei" << endl;	
	}
	return 0;
}
