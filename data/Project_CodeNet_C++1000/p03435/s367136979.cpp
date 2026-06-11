#include<bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
	if(y == 0) return x;
	else return gcd(y, x % y);
}

int main() {
	int c[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> c[i][j];
		}
	}

	int a[3] = {}, b[3];
	for(int i = 0; i < 3; i++) b[i] = c[0][i];
	a[1] = c[1][0] - b[0];
	a[2] = c[2][0] - b[0];
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(c[i][j] != a[i] + b[j]) {
				ok = false;
				break;
			}
		}
	}

	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
