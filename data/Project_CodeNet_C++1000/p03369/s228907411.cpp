#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	string s;
	int c = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] == 'o') c++;
	cout << 700 + 100 * c << endl;

	return 0;
}