#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, k;
	int sum = 1;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		if ((sum + k) > sum * 2) { sum += sum; }
		else if ((sum + k) <= sum * 2) { sum += k; }
	}
	cout << sum << endl;
}