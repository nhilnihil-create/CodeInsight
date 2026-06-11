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
	ll n;
	cin>>n;
	string s;
	double d,sum = 0;
	std::setprecision(5);
	rep(i,1,n)
	{
		cin>>d>>s;
		if(s.compare("BTC") == 0)
			d *= 380000.0;
		sum += d;
	}
	cout<<fixed<<sum;
	
}
