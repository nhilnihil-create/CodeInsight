#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

const string defaultval = "753";

ll dfs(string s, ll n)
{
	ll x  = stoll(s);
	if(x > n)
		return 0;
	ll ret = 0;
	if(count(s.begin(), s.end() , '7') > 0 &&count(s.begin(), s.end() , '5') > 0 && count(s.begin(), s.end() , '3') > 0)
		ret = 1;

	for(char c :defaultval)
	{
		s.push_back(c);
		ret += dfs(s, n);
		s.pop_back();
	}
	return ret;
}		



int main()
{
	ll n;
	cin>>n;
	string start = "0";
	cout<<dfs(start, n);

}
