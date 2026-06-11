#include <iostream>
#include <string>

using namespace std;

string tr = "keyence";

bool sol(string str, int i) {
	for (int k = 0; k <= i; k++) {
		if (str[k] != tr[k]) {
			return false;
		}
	}
	int j = 1;
	for (int k = str.size() - tr.size()+i+1; k < str.size(); k++) {
		if (str[k] != tr[i+j]) {
			return false;
		}
		j++;
	}
	return true;
}

int main() {
	
	string str;
	cin >> str;

	bool flag = false;
	for (int i = 0; i < tr.size(); i++) {
		if (sol(str, i)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}