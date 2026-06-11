#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 8;
int n , a[N] , l = -1 , r , mid , v , q;
pair<int, int> k , z;
set<pair<int , int> > s;

bool is_val(int x)
{
	s.clear();
	s.insert({0 , 0});
	for(int i = 1 ; i < n ; i++)
	{
		k = *s.rbegin();
		if(a[i] > a[i - 1])
		{
			if(k.second != 0)
				s.insert({a[i - 1] + 1 , 0});
		}
		else
		{
			while(s.size() && s.rbegin()-> first > a[i])
				s.erase(*s.rbegin());
			v = s.rbegin()-> second , q = s.rbegin()-> first;
			if(v != x)
			{
				if(s.rbegin()->first == a[i])
					s.erase(*s.rbegin());
				if(s.empty() || (s.size() && s.rbegin()->second != v + 1))
					s.insert({a[i] , v + 1});
			}
			else
			{
				if(q == 0)
					return 0;
				s.erase(*s.rbegin());
				z = *s.rbegin();
				if(z.first + 1 == q)
					s.erase(*s.rbegin());
				if(s.empty() || (s.size() && s.rbegin()->second != z.second + 1))
					s.insert({q - 1 , z.second + 1});
				s.insert({q , 0});
			}
		}
	}
	return 1;
}

int main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	r = n;
	while(r - l > 1)
	{
		mid = (l + r) / 2;
		if(is_val(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r + 1;
}