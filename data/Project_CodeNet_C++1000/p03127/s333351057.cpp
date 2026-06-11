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
	ll N;
	cin>>N;
	vi A(N);
	rep(i,0,N-1)
		cin>>A[i];

	ll mi = *min_element(A.begin(), A.end());
	ll prev = -1;
	while(mi != 0 && prev != mi)
	{
		rep(i, 0, N-1)
		{
			if(A[i] % mi == 0)
				A[i] = mi;
			else
				A[i] %= mi;
		}
		prev = mi;
		mi = *min_element(A.begin(), A.end());
	}

	cout<<mi;
	
}
