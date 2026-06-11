#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	int k = b - a;
	if(b % a == 0)
	{
		k = a + b;
	}
	cout << k << endl;
	return 0;
}
