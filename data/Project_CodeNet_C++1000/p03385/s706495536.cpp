#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	string s;
	cin >> s;
	if (s == "abc" || s == "acb" || s == "bac" || s == "bca" || s == "cab" || s == "cba") cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
