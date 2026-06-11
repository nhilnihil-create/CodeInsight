#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	bool f = false;
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 15; ++j) {
			int total = 4 * i + 7 * j;
			if (total == N) f = true;
		}
	}

	cout << (f ? "Yes" : "No") << endl;
}