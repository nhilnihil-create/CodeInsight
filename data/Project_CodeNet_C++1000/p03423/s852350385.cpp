#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ff first
#define ss second

void solve()
{
	int n;
	cin>>n;
	int x = (n - 1) / 3 + 1;
	if (n % 3 != 0) x--;
	cout<<x<<endl;
}

int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
