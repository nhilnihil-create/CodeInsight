#include <bits/stdc++.h>
 
using namespace std;

class LadderPermutation
{
public:
	vector <int> createLadder(long long int n,long long int m,long long int k)
	{
		if(m+k-1>n || n>m*k)
		{
			return {};
		}
		vector <int> res;
		vector <int> v;
		long long int num = n;
		for(int i=0;i<k;i++)
		{
			v.push_back(num);
			num--;
		}
		
		for(int i=0;i<v.size();i++)
		{
			if(num==0)
			{
				res.push_back(v[i]);
			}
			else
			{
				int start = max(1LL,num-m+2);
				int end = num;
				for(int j=start;j<=end;j++)
				{
					res.push_back(j);
				}
				num-=(m-1);
				if(num < 0)
				{
					num = 0;
				}
				res.push_back(v[i]);
			}
		}
		if(num>=1)
		{
			for(int i=1;i<=num;i++)
			{
				res.push_back(i);
			}
		}
		return res;
	}
}; 
int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	long long int n,m,k;

	cin >> n >> m >> k;
	LadderPermutation p;

	vector <int> res = p.createLadder(n,m,k);

	if(res.size()==0)
	{
		cout << -1 << '\n';
		return 0;
	}
	for(auto it : res)
	{
		cout << it << ' ';
	}
	cout << '\n';

	return 0;
}