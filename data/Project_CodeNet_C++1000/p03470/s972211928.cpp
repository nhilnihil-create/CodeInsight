#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> mochi;
	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;  mochi.push_back(j);
	}
	int dan = 0;
	vector<int> name(1,0);
	for (int i = 0; i < n; i++)
	{
		for (int x = 0; x < name.size(); x++ )
		{
			if (mochi.at(i) == name.at(x))break;
			if (x+1 == name.size())
			{
				name.push_back(mochi.at(i));
				dan++;
			}
		}
	}
	cout << dan << endl;

}