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
	for (int i=0;i<(1<<n);i++)
	{
		vector<bool> biti(20);
		for (int j=0;j<n;j++) if (i & (1<<j)) biti[j]=1;
		for (int j=0;j<n;j++)
			for (int k=j+1;k<n;k++)
				if (biti[j]&biti[k]) tac[i]+=a[j][k];
	}
	for (int i=0;i<(1<<n)-1;i++)
	{
		vector<int> v;
		for (int j=0;j<n;j++) if (!(i & (1<<j))) v.push_back(j);
		int t=0;
		for (int j=0;j<(1<<v.size());j++)
		{
			d[i+t]=max(d[i+t],d[i]+tac[t]);
			int ti=j,cnt=0;
			while (ti&1) ti>>=1,t-=(1<<v[cnt++]);
			if (cnt!=n) t+=(1<<v[cnt]);
		}
	}
	cout <<d[(1<<n)-1];
	return 0;
} 