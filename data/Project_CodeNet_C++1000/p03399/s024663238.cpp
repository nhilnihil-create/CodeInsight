#include<iostream>


using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int train_lowCost = 0;
	int bus_lowCost = 0;

	if (A < B) {
		train_lowCost = A;
	}
	else {
		train_lowCost = B;
	}

	if (C < D) {
		bus_lowCost = C;
	}
	else {
		bus_lowCost = D;
	}

	cout << train_lowCost + bus_lowCost << endl;
}
