#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	ll t[n];
	for (int i = 0; i < n; i++)cin>>t[i];
	ll g = __gcd(t[0],t[1]);
	for (int i = 2; i < n; i++)
	{
		g=__gcd(g,t[i]);
	}
	cout << g;
}