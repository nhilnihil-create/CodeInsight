#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> crd(n);

	for (int i = 0; i < n; i++)
	{
		cin >> crd.at(i);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (crd.at(i) < crd.at(j)) swap(crd.at(i), crd.at(j));
		}
	}
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2) b += crd.at(i);
		else a += crd.at(i);
	}
	cout << a - b << endl;

}
