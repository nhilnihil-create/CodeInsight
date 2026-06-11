#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100100
int a[sz];
int b[sz];
int c[sz];
int dpa[sz];
int dpb[sz];
int dpc[sz];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++)
	{
		dpa[i] = max(dpb[i - 1], dpc[i - 1]) + a[i - 1];
		dpb[i] = max(dpa[i - 1], dpc[i - 1]) + b[i - 1];
		dpc[i] = max(dpa[i - 1], dpb[i - 1]) + c[i - 1];
	}
	cout << max(dpa[n], max(dpb[n], dpc[n]));
	return 0;
}