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
	string s;
	cin>>s;

	int num = (s[0] - '0') *100 + (s[1]- '0') * 10 + (s[2]- '0');
	int l = s.length();
	int min_diff =  753;
	rep(i,3, l - 1)
	{
		min_diff = min(min_diff, abs(753 - num));
		num = num - 100 * (s[i-3] - '0');
		num = num * 10 + (s[i] - '0');
	}
	cout<< min(min_diff, abs(753 - num));

}
