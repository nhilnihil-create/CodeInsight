#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int s = 0, m = n;
	while (n > 0)
	{
		s += n % 10;
		n /= 10;
	}
	if (m % s)
		cout << "No" << endl;
	else 
		cout << "Yes" << endl;
}
