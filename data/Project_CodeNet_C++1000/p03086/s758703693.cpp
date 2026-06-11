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
	string s;
	cin>>s;
	
	vi cnt(s.length(), 0);

	if(s[0] == 'A' || s[0]=='C'||s[0]=='G'||s[0]=='T')
		cnt[0] = 1;

	rep(i, 1, s.length())
		if(s[i] == 'A' || s[i]=='C'||s[i]=='G'||s[i]=='T')
			cnt[i] = cnt[i-1] + 1;

	cout<<*max_element(cnt.begin(), cnt.end());
}