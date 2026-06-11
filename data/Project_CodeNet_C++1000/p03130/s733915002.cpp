#include <iostream>
using namespace std;

int main() {
	int nodes[4] = { 0,0,0,0 };
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		nodes[x - 1]++;
		nodes[y - 1]++;
	}
	for (int i = 0; i < 4; i++) {
		if (nodes[i] == 3) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}