#include<bits/stdc++.h>

#define fo(i,n)   for(i=0;i<n;i++)
#define mod       1000000007
using namespace std;

int main()
{


	int n, m, c;
	cin >> n >> m >> c;

	int a[m];
	for (int i = 0; i < m; i++)
		cin >> a[i];
	int b[n][m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += b[i][j] * a[j];
		}
		sum += c;
		if (sum > 0)
			cnt++;
	}
	cout << cnt << endl;
}
