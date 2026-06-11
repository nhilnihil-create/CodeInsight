#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int h,w,n,sh,sw;
	string s,t;
	cin>>h>>w>>n>>sh>>sw>>s>>t;
	--sh;--sw;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int l=0,r=w,u=0,d=h;
	for (int i = 0; i < n; ++i)
	{
		if (t.at(i)=='L')
		{
			r=min(w,r+1);
			if (r==l)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else if (t.at(i)=='R')
		{
			l=max(0,l-1);
			if (r==l)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else if (t.at(i)=='U')
		{
			d=min(h,d+1);
			if (u==d)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else if (t.at(i)=='D')
		{
			u=max(0,u-1);
			if (u==d)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		if (s.at(i)=='L')
		{
			++l;
			if (r==l)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else if (s.at(i)=='R')
		{
			--r;
			if (r==l)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else if (s.at(i)=='U')
		{
			++u;
			if (u==d)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else if (s.at(i)=='D')
		{
			--d;
			if (u==d)
			{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	if (l<=sw&&sw<r&&u<=sh&&sh<d)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}
