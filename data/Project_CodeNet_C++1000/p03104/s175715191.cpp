#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int f(int n)
{
	if(n%4 == 0)
		return n;
	if(n%4 == 1)
		return 1;
	if(n%4 == 2)
		return n + 1;
	return 0;
}

int32_t main()
{
	IOS;
	int a, b;
	cin>>a>>b;
	int ans = f(b) ^ f(max(0LL, a - 1));
	cout<<ans;
	return 0;
}
