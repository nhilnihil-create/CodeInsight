#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	double n,m,d;
	cin >> n >> m >> d;
	double ans;
	if (d == 0)
	{
		ans = 1/n;
	}
	else
	{
		ans = 2*(n-d)/n/n;
	}
	ans *= m-1;
	cout << setprecision(10) << ans << endl;
	return 0;
}