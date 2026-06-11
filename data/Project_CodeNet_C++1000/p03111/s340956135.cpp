#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
 
ll A,B,C, N;
vi l;

int dfs(int idx,int a,int b,int c)
{
	if(N == idx)
	{
		if(min({a,b,c}) == 0)
			return INT_MAX;
		return abs(a-A) + abs(b-B) + abs(c - C);  
	}

	int ret1 = dfs(idx + 1, a,b,c);

	int ret2 = dfs(idx + 1, a + l[idx],b,c);
	if(a != 0 && ret2 != INT_MAX)
		ret2 += 10;

	int ret3 = dfs(idx + 1, a,b + l[idx],c);
	if(b != 0 && ret3 != INT_MAX)
		ret3+=10;

	int ret4 = dfs(idx + 1, a,b,c + l[idx]);
	if(c != 0 && ret4 != INT_MAX)
		ret4+=10;

	
	return min({ret1,ret2,ret3,ret4});
	
}

int main()
{
	//ifstream cin("input.txt");
	cin>>N>>A>>B>>C;
	l = vi(N);
	rep(i,0,N-1)
		cin>>l[i];

	cout<<dfs(0,0,0,0);
	
}
