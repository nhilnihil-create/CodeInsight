#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int d;
	cin >> d;

	string s = "Christmas";

	int rem = 25 - d;

	for (int ii = 0; ii < rem; ++ii){
		s += " Eve";
	}

	cout << s << "\n";

	return 0;
}
