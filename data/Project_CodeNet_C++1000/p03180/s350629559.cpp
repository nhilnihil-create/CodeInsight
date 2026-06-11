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
ll d[65540];
ll ad[65540];
int main()
{
	cin >>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin >>a[i][j];
	for (int i=1;i<(1<<n);i++)
	{
		vector<int> v;
		for (int j=0;j<n;j++) if (i & (1<<j)) v.push_back(j);
		for (int j=0;j<v.size();j++)
			for (int k=j+1;k<v.size();k++)
				ad[i]+=a[v[j]][v[k]];
	}
	fill(d,d+(1<<n),-1e18);
	d[0]=0;
	for (int i=1;i<(1<<n);i++)
	{
		vector<int> v;
		for (int j=0;j<n;j++) if (i & (1<<j)) v.push_back(j);
		for (int j=1;j<(1<<(int)v.size());j++)
		{
			int t=0;
			for (int k=0;k<v.size();k++) if (j & (1<<k)) t|=(1<<v[k]);
			d[i]=max(d[i],ad[t]+d[i^t]);
		}
	}
	cout <<d[(1<<n)-1];
	return 0;
} 