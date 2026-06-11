#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;


int ds(int x)
{
	int res = 0;
	while(x)
	{
		res += x%10;
		x/=10;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int ans = n;
	for(int i = 1;i<n;i++)
	{
		int now = 0;
		now = ds(i);
		now += ds(n-i);
		ans = min(ans,now);
	}
	cout  << ans << endl;
}
