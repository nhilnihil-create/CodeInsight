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
	sort(crd.rbegin(), crd.rend());
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if(!(i%2)) a += crd.at(i);
		else b += crd.at(i);
	}
	cout << (max(a, b) - min(a, b)) << endl;
}
