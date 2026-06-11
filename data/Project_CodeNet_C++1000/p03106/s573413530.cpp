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
	ll a,b, k;
	cin>>a>>b>>k;
	vi divs;
	int m = min(a,b);
	rep(i, 1, m)
		if(a%i == 0 && b%i == 0)
			divs.push_back(i);
	cout<<divs[divs.size() - k];
	
}
