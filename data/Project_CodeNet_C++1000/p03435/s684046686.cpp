#include<bits/stdc++.h>
using namespace std;


int s, c, i = 9;

int main()
{
	while (i--)
	{
		cin >> c;
		s += (i % 4 ? c : -2 * c);
	}
	cout << (s ? "No" : "Yes") << endl;
}

