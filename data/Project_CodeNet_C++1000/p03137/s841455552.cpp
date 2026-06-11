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
	ll n,m;
	cin>>n>>m;
	vi x(m);

	if(m == 1 || n >= m)
	{
		cout<<0;
		return 0;
	}
	rep(i,0,m-1)
		cin>>x[i];

	vi diff(m-1);

	sort(x.begin(), x.end());
	rep(i, 1, m-1)
		diff[i-1] = abs(x[i] - x[i - 1]);

	sort(diff.begin(), diff.end());
	int poss_distance = 0, j =0;
	rep(i, 1, m- n )
		poss_distance += diff[j++];
	
	cout<<poss_distance;
	
}
