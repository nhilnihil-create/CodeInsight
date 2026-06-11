#include "bits/stdc++.h"
using namespace std;

int main() {
	int n,dmin;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num,d = 0;
		cin >> num;
		while (!(num % 2)) {
			num /= 2;
			d++;
		}
		if (!i || (dmin > d)) { dmin = d; }
	}
	cout << dmin << endl;
}