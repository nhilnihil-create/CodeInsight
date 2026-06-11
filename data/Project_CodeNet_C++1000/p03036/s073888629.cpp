#include"bits/stdc++.h"

using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define sp " "
#define int long long
#define PI 3.141592653589793
#define scanstr(s) cin>>ws; getline(cin,s);

void solve()
{
	int r,d,be;
	cin>>r>>d>>be;
	vector<int> ans;
	for(int i=0;i<10;i++)
	{
		int a=r*be-d;
		cout<<a<<nl;
		be=a;
	}
	return ;
}

int32_t main()
{
	FastIO;
	solve();
	return 0;
}
