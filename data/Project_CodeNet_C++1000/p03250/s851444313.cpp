#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string a[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + 3, greater<string>());
	cout << stoi(a[0] + a[1]) + stoi(a[2]) << endl;
	return 0;
}