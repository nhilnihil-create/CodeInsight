#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<string> A(n);
	for (int i = 0; i < n; i++)cin >> A.at(i);
	cin >> m;
	vector<string> B(m);
	for (int i = 0; i < m; i++)cin >> B.at(i);
	vector<string> name(m+n, " ");
	vector<int> mny(m+n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A.at(i) == name.at(j))
			{
				mny.at(j)++;
				break;
			}
			else if (name.at(j) == " ")
			{
				name.at(j) = A.at(i); mny.at(j)++;
				break;
			}
		}

	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (B.at(i) == name.at(j))
			{
				mny.at(j)--;
				break;
			}
			else if (name.at(j) == " ")
			{
				name.at(j) = B.at(i); mny.at(j)--;
				break;
			}
		}

	}

	int max = 0;
	for (int i = 0; i < m+n; i++)
	{
		if (max < mny.at(i)) max = mny.at(i);
		// cout << name.at(i) << " " << mny.at(i) << endl;
	}
	cout << max << endl;

}
