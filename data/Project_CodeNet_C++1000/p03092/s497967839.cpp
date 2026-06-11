#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e3 + 5;
int n,p[N],not_inv[N];
LL A,B,f[N][N];
//#define R
int main()
{
	cin>>n>>A>>B;
	for (int i = 1;i <= n; ++i)
		cin>>p[i]; 
	for (int i = 1;i <= n; ++i)
	{
		not_inv[i] = 0;
		for (int j = 1;j < i; ++j)
			if (p[j] < p[i])
				not_inv[i]++;
	}
	for (int i = 1;i <= n; ++i)
		for (int j = 1;j <= i; ++j)
			if (not_inv[i] + 1 > j)
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = min(f[i - 1][j - 1] + B,f[i - 1][not_inv[i]] + A * ((LL)j - 1 - not_inv[i])); 
				//f[i - 1][not_inv[i]] + min(A,B * ((LL)j - 1 - not_inv[i]));
	#ifdef R
	for (int i = 1;i <= n; ++i)
	{
		for (int j = 1;j <= n; ++j)
			cout<<f[i][j]<<" ";
		puts("");
	}
	#endif
	cout<<f[n][n];
 } 