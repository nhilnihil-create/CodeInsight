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
	ll n,k;
	cin>>n>>k;
	vi h(n);

	rep(i,0,n-1)
		cin>>h[i];
	
	sort(h.begin(), h.end());
	ll min_k = INT_MAX;
	rep(i, k - 1, n-1)
		min_k = min(min_k, h[i] - h[i - k + 1]);
	
	cout<<min_k;

}
