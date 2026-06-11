#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	if (a > b)swap(a, b);
	int counter = 0;
	for (size_t i = a; i >= 1; i--)	{
		if (a % i == 0 && b % i == 0)counter++;
		if (counter == k) {
			cout << i << endl;
			return 0;
		}
	}
}