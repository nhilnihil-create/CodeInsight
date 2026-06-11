#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, cnt = 0;
	cin >> A >> B;

	for (int i = A; i < B+1; i++)
	{
		if (i / 1000 == i % 10 * 10 + i / 10 % 10)
			cnt++;
	}

	cout << cnt << endl;
}