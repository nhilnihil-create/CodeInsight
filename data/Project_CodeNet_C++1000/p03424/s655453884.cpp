#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> arare;
	for (int i = 0; i < n; ++i) {
		string color;
		cin >> color;
		bool ok = true;
		for (int j = 0; j < (int)arare.size(); ++j) {
			if (color == arare[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			arare.push_back(color);
		}
	}

	if (arare.size() == 3)
		cout << "Three" << endl;

	if (arare.size() == 4)
		cout << "Four" << endl;

	return 0;
}