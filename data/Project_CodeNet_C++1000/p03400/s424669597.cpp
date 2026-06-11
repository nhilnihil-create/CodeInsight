#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int N, D, X, *a, sum = 0;

	cin >> N >> D >> X;;

	a = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < N; i++) {
		sum += (D - 1) / a[i] + 1;
	}

	cout << sum + X;

	return 0;
}