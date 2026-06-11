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
	int m,n;
	cin>>n>>m;
	int a[m],b[m];
	for(int i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
	}
	int mn=*max_element(a,a+m);
	int mx=*min_element(b,b+m);
	cout<<max(0LL,mx-mn+1)<<endl;
}

int32_t main()
{
	FastIO;
	solve();
	return 0;
}
