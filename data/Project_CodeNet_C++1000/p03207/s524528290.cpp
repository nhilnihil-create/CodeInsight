#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;



int main() {
	int n;
	int p[11];
	int pmax;
	int total = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	pmax = p[0];
	for (int i = 0; i < n; i++) {
		if (p[i]>pmax) {
			pmax = p[i];
		}

		total += p[i];
	}

	total -= pmax / 2;

	cout << total;
}