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
	int n,m,c;
	cin>>n>>m>>c;
	ll sum, count = 0,x;

	vi b(m);
	rep(i,0,m-1)
		cin>>b[i];

	rep(i,0,n-1){
		sum = 0;	
		rep(j,0, m -1)
			{
				cin>>x;
				sum += x*b[j];
			}
			sum +=c;

		if(sum > 0)
			count++;	
	}
	cout<<count;
		
	
}
