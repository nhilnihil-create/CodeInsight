#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	double t, a; cin >> t >> a;
	int index = 0;
	double minval = 1e9;
	for (int i = 0; i < n; ++i)
	{
		double h; cin >> h;
		if (abs(a-t+h*.006) < minval)
		{
			minval = abs(a-t+h*.006);
			index = i+1;
		}
	}
	cout << index << endl;
}


