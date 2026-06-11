#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace  std;

int main() {
	int N,X;
	cin >> N>>X;
	int sum = 0;
	int val;
	int minimum = INT_MAX;
	int donuts=N;
	for (int i = 0; i < N; i++) {
		cin >> val;
		sum += val;
		if (val < minimum)minimum = val;
	}
	donuts += (int)(X - sum) / minimum;
	cout << donuts << endl;
	return 0;
}