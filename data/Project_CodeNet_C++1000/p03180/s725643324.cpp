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
ll a[20][20];
ll d[65540],tac[65540];
int main()
{
	cin >>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin >>a[i][j];
	for (int i=1;i<(1<<n);i++)
	{
		int t=0;
		while (!(i & (1<<t))) t++;
		tac[i]=tac[i^(1<<t)];
		for (int j=t+1;j<n;j++) if (i & (1<<j)) tac[i]+=a[t][j];
	}
	for (int i=1;i<(1<<n);i++)
	{
		//cout <<i<<" ###########\n";
		for (int j=0;j<n;j++)
		{
			if (!(i & (1<<j))) continue;
			int k=i^(1<<j);
			d[i]=tac[i];
			while (1)
			{
				//cout <<k<<" "<<j<<" "<<(k^(1<<j))<<" "<<d[i]<<" ##\n";
				d[i]=max(d[i],d[i^k^(1<<j)]+tac[k^(1<<j)]);
				if (!k) break;
				k=(k-1)&(i^(1<<j));
			}
		}
	}
	cout <<d[(1<<n)-1];
	return 0;
}