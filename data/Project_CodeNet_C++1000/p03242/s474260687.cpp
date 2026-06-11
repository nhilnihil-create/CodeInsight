#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	string n;
	cin >> n;
	for (int i = 0; i < n.length(); i++) {
		if (n[i] == '1') n[i] = '9';
		else if (n[i] == '9') n[i] = '1';
	}
	cout << n << endl;

	return 0;
}
