#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	int m = stoi(s.substr(5, 2));
	int d = stoi(s.substr(8, 2));
	if (m <= 4)cout << "Heisei" << endl;
	else cout << "TBD" << endl;
}