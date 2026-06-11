#include "bits/stdc++.h"
using namespace std;

int main() {
	string s;
	cin >> s;

	int f = s.rfind("FESTIVAL");

	cout << s.substr(0, f) << endl;
}
