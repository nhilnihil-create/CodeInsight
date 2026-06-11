#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	map<int, int> M;
	cin >> n;
	for (int i = 1;;i++)
	{
		if (M[n] != 0)
		{
			cout << i << endl;
			break;
		}
		M[n] = i;
		n = (n%2==0?n/2:3*n+1);
	}
	return 0;
}