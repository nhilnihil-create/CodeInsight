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
	//ifstream cin("input.txt");
	ll n,m,a,b;
	cin>>n>>m;
	
	vector<pair<ll, ll>> nums(n);
	rep(i,0, n-1){
		cin>>a>>b;
		nums[i] = make_pair(a, b);
	}

	sort(nums.begin(), nums.end());
	ll count = 0, cost = 0,i = 0;
	while(count < m)
	{
		if(count + nums[i].second > m)
		{
			cost += (m - count) * nums[i].first;
			count = m;
		}
		else
		{
			cost += nums[i].first * nums[i].second;
			count += nums[i].second;
		}
		i++;
	}
	cout<<cost;
	
}
