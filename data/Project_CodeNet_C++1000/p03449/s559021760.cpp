#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[2][n];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	int res = a[0][0];
	for(int i = 0; i < n; i++) res += a[1][i];
	int tmp = res;
	for (int i = 0; i < n-1; i++)
	{
		tmp += - a[1][i] + a[0][i+1];
		res = max(res, tmp);
	}
	cout << res << endl;
	return 0;
}
