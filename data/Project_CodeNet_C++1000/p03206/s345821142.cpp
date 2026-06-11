#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	int D;
	cin >> D;
	cout << "Christmas";
	while (D < 25) {
		cout << " Eve";
		D++;
	}
}
