#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;



int main() {
	string target = "keyence";
	string str;
	cin >> str;
	for (size_t i = 0; i < str.length() + 1; i++)
	{
		if (target.substr(0, i) == str.substr(0, i) && target.substr(i) == str.substr(str.size() - target.size() + i)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}