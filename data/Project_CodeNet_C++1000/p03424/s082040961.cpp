#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<char> s(n);
	bool y=false;
	for (int i = 0; i < n; i++) {
		cin >> s.at(i);
		if (s.at(i) == 'Y') y = true;
	}
	if (y) {
		cout << "Four" << endl;
	}
	else {
		cout << "Three" << endl;
	}

}