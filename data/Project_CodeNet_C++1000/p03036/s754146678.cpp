#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
   	
int main() {
	int r, d, x, a;

	cin >> r >> d >> x;
	a = r*x - d;

	for (int i = 0; i < 10; i++)
	{
		cout << a << endl;
		a = r*a - d;
	}

	return 0;
}

