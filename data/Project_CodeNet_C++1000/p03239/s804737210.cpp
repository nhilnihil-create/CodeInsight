#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;


int main()
{
	
	int n, t;
	cin>>n>>t;
	int c, ti;
	vector<pair<int,int>> ct;
	rep(i ,0, n-1)
	{
		cin>>c>>ti;
		ct.push_back(make_pair(c, ti));
	}
	sort(ct.begin(), ct.end());
	
	for(auto pi : ct)
	{
		if(pi.second <= t)
		{
			cout<<pi.first;
			return 0;
		}

	}
	cout<<"TLE";
	return 0;
}
