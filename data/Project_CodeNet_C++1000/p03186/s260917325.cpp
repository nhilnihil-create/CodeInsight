#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,c,sm=0;
	cin >> a >> b >> c;
	if(c > a + b)
	{
		sm = b + a + b + 1;
	}
	else
	{
		sm = b + c;
	}
	cout << sm << endl;
	return 0;
}
