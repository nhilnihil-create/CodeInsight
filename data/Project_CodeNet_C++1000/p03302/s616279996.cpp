#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	char k = 'x';
	if(a + b == 15)
	{
		k = '+';
	}
	else if(a * b == 15)
	{
		k = '*';
	}
	cout << k << endl;
	return 0;
}
