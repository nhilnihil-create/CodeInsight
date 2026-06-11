#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int dishes[5];
	for (int i = 0; i < 5; i++) cin >> dishes[i];

	int ones_place = dishes[0] % 10;
	for (int i = 1; i < 4; i++) {
		if (dishes[i] % 10 == 0) continue;
		ones_place = min(ones_place, dishes[i] % 10);
	}
	int last_index;
	for (int i = 0; i < 5; i++) {
		if (ones_place == dishes[i] % 10) last_index = i;
	}
	int time = 0;
	for (int i = 0; i < 5; i++) {
		if (i == last_index || dishes[i] % 10 == 0) time += dishes[i];
		else time += dishes[i] + (10 - dishes[i] % 10);
	}
	cout << time << endl;

	return 0;
}