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
	vi a(5);
	cin>>n;
	rep(i,0,4)
	{
		cin>>a[i];
	}

	int min_idx = min_element(a.begin(), a.end()) - a.begin();
	if(a[min_idx] >= n)
		cout<<5;
	else
		cout<<(ll)ceil((long double)n/a[min_idx]) + (4 - min_idx) + min_idx;
	
	

}