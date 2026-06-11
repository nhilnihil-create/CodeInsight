#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin >> s;
  	int n = stoi(s.substr(0, 4) + s.substr(5, 2) + s.substr(8, 2));
    if (n > 20190430) {
        cout << "TBD" << endl;
    } else {
        cout << "Heisei" << endl;
    }
	return 0;
}