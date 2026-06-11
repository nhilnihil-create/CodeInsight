#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PLI pair<ll, int>
#define PIL pair<int, ll>
#define STR string
#define Fst first
#define Snd second
#define SHN 1e9
#define LSHN 1e18
using namespace std;
int n;
ll d[65540],tac[65540];
ll a[20][20];
int main()
{
	cin >>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin >>a[i][j];
	for (int i=0;i<(1<<n);i++)
	{
		for (int j=0;j<n;j++)
		{
			if (!(i & (1<<j))) continue;
			for (int k=j+1;k<n;k++) if (i & (1<<k)) tac[i]+=a[j][k];
		}
	}
	for (int i=1;i<(1<<n);i++)
	{
		d[i]=tac[i];
		for (int j=i;j>0;j=(j-1)&i) d[i]=max(d[i],d[i^j]+tac[j]);
	}
	cout <<d[(1<<n)-1];
	return 0;
} 