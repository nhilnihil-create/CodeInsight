#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> mochi(n);
	for (int i = 0; i < n; i++)
	{
		cin >> mochi.at(i);
	}
	sort(mochi.rbegin(), mochi.rend());
	int dan = 1;
	for (int i = 0; i < n; i++)
	{
		if (!i) continue;
		if (mochi.at(i) < mochi.at(i - 1)) dan++;
	}
	cout << dan << endl;
}
