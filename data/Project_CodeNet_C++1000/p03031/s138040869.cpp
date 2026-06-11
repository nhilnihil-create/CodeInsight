#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> s(10,vector<int>(10,0));
	for(int i=0;i<m;i++)
	{
		int k;
		cin >> k;
		for(int j=0;j<k;j++)
		{
			cin >> s.at(i).at(j);
		}
	}
	vector<int> p(m,0);
	for(int i=0;i<m;i++)
	{
		cin >> p.at(i);
	}
	int ans=0;
	vector<int>b(n,0);
	for(int i=0;i<pow(2,n);i++)
	{
		int d=i;
		for(int j=0;j<n;j++)
		{
			b.at(j)=d%2;
			d/=2;
		}
		int f=0;
		for(int j=0;j<m;j++)
		{
			int sm=0;
			for(int l=0;l<n;l++)
			{
				int w=s.at(j).at(l);
				if(w>0)
				{
					sm+=b.at(w-1);
				}
			}
			if(sm%2!=p.at(j))
			{
				f++;
			}
		}
		if(f==0)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
