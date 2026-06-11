#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

int findContinuousIntervals(vi &h, int n)
{
	int i = 0, res = 0;
	while(i < n)
	{
		if(h[i] == 0)
			i++;
		else
		{
			res ++;
			while(i< n && h[i] >0)
				i++;
		}
	}
	return res;
}

int main()
{
	//ifstream cin("input.txt");
	ll n;
	cin>>n;
	vi h(n);

	rep(i,0,n-1)
		cin>>h[i];
	int count = 0;
	while(*max_element(h.begin(), h.end()) != 0)
	{
		count += findContinuousIntervals(h,n);
		rep(i, 0, n-1)
			if(h[i] >0)
				h[i]--;
	}
	cout<<count;
}
