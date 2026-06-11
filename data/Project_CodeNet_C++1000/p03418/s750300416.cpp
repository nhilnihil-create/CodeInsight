#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int n,m;
int main()
{
	cin >> n >> m;
	long long ans=0;
	for(int i=m+1; i<=n; i++)
	{
		ans+=(i-m)*(n/i)+max(0,(n%i)-m+1);
		if(!m) ans--;
		//cout << i << ' ' << (i-m)*(n/i)+max(0,(n%i)-m+1)<<'\n';
	}
	cout << ans;
	return 0;
}
