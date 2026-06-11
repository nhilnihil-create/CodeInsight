#include <bits/stdc++.h>
using namespace std;

int main()
{
	char ar[4];
	char ar1[4];
    for(int i = 0; i < 3; ++i)
	{
		cin >> ar[i];
	}
	ar1[0] = ar[0];
	for (int i = 0; i < 3; ++i)
	{
		cin >> ar[i];
	}
	ar1[1] = ar[1];
	for (int i = 0; i < 3; ++i)
	{
		cin >> ar[i];
	}
	ar1[2] = ar[2];

	for (int i = 0; i < 3; ++i)
	{
		cout << ar1[i];
	}
	cout << endl;

}
