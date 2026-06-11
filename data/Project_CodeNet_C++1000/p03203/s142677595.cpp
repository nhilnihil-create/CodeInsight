#include <bits/stdc++.h>
 
using namespace std;

set <pair<int,int>> s;
int h,w,n,x,y;
set <int> obs[200001];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> h >> w >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		s.insert(make_pair(x,y));
		obs[y].insert(x);
	}

	long long int res = 1e18;
	long long int cnt = 0;
	x = 1;
	y = 1;
	bool flag = true;
	int turn = 0;
	while(1)
	{
		//cout << x << ' ' << y << '\n';
		auto it = obs[y].lower_bound(x);
		if(it==obs[y].end())
		{
			res = min(res,cnt + h  + 1 - x);
		}
		else
		{
			//cout << x << ' ' << y << ' ' << *it << ' ' << cnt << ' ' << *it - x << '\n';
			res = min(res,cnt + (*it - x));
		}
		if(turn==0)
		{
			cnt++;
			if(x==h)
			{
				if(flag==false)
				{
					break;
				}
				flag = false;
			}
			else
			{
				if(s.find(make_pair(x+1,y))!=s.end())
				{
					if(flag==false)
					{
						break;
					}
					flag = false;
				}
				else
				{
					//cnt++;
					x += 1;
					flag = true;
				}
			}
			turn = 1;
		}
		else
		{
			if(y==w)
			{
				if(flag==false)
				{
					break;
				}
				flag = false;
			}
			else
			{
				if(s.find(make_pair(x,y+1))==s.end())
				{
					y += 1;
					flag = true;
				}
				else
				{
					if(flag==false)
					{
						break;
					}
					flag = false;
				}
			}
			turn = 0;			
		}
	}

	cout << res << '\n';

	return 0;	
}
