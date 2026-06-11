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
	int c = 1;
	while(n > 4 || n == 3)
	{
		c++;
		if(n%2 == 0)
			n = n/2;
		else
			n = 3*n + 1;
	}
	cout<<c + 3;
	
}
