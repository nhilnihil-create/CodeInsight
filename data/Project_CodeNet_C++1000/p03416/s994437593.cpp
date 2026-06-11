#include "bits/stdc++.h"
using namespace std;

int main() {
	int a, b;
	int cnt = 0;
	cin >> a >> b;
	for (int i = a; i < b + 1; i++)
	{
		if (i / 1000 == i % 10 * 10 + i / 10 % 10) cnt++;
	}
	cout << cnt << endl;
}