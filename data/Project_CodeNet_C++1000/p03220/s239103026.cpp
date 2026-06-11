#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	double T, A;
	cin >> N >> T >> A;
	double min_value = 1LL << 60;
	int min_index = -1;
	for (int i = 0; i < N; ++i) {
		double H;
		cin >> H;
		double diff = abs((T - H * 0.006) - A);
		if (diff < min_value) {
			min_value = diff;
			min_index = i;
		}
	}
	cout << min_index + 1 << endl;
}