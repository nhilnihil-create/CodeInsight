#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	int x,y;
	cin>>s>>x>>y;
	int now=0;
	while (s[now]=='F')
	{
		++now;
	}
	vector<int> h,w;
	int d=0,cnt=0;
	for (int i = now; i < s.size(); ++i)
	{
		if (s[i]=='F')
		{
			++cnt;
		}
		else
		{
			if (cnt==0)
			{
				++d;
				continue;
			}
			if (d%2==0)
			{
				h.push_back(cnt);
			}
			else
			{
				w.push_back(cnt);
			}
			++d;cnt=0;
		}
	}
	if (cnt>0)
	{
		if (d%2==0)
		{
			h.push_back(cnt);
		}
		else
		{
			w.push_back(cnt);
		}
	}
	int dph[h.size()+5][2*s.size()+5]={},dpw[w.size()+5][2*s.size()]={};
	dph[0][now+s.size()]=1;
	for (int i = 0; i < h.size(); ++i)
	{
		for (int j = 0; j < 2*s.size()+5; ++j)
		{
			if (j-h[i]>=0)
			{
				dph[i+1][j-h[i]]|=dph[i][j];
			}
			if (j+h[i]<2*s.size()+5)
			{
				dph[i+1][j+h[i]]|=dph[i][j];
			}
		}
	}
	dpw[0][s.size()]=1;
	for (int i = 0; i < w.size(); ++i)
	{
		for (int j = 0; j < 2*s.size()+5; ++j)
		{
			if (j-w[i]>=0)
			{
				dpw[i+1][j-w[i]]|=dpw[i][j];
			}
			if (j+w[i]<2*s.size()+5)
			{
				dpw[i+1][j+w[i]]|=dpw[i][j];
			}
		}
	}
	if (dph[h.size()][x+s.size()]==1&&dpw[w.size()][y+s.size()]==1)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}
