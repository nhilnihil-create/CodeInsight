#include <iostream>
using namespace std;
int main() {
	int N;
	int count = 0;
	cin >> N;
	int* d = new  int[N];
	bool* same = new bool[N];
	for (int i = 0;i < N;i++) {
		cin >> d[i];
		same[i] = false;
	}
	for (int k = 0;k < N;k++) {
		if (same[k] == false) {
			count++;
			for (int j = k + 1;j < N;j++) {
			if (d[k] == d[j])
				same[j] = true;
		}
		}
	}


	cout << count;
}