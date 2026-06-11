#include <iostream>
using namespace std;

int main() {
	int nums[4] = { 1,9,7,4 };
	int exists = 0;
	for (int i = 0; i < 4; i++) {
		int N;
		cin >> N;
		for (int j = 0; j < 4; j++) if (N == nums[j]) exists += (1 << j);
	}
	cout << (exists == 15 ? "YES" : "NO") << endl;
}