#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
int main()
{
	cin>>n;
	vector<int> l(n+1,0),r(n+1,0);
	for (int i=1;i<=n;++i) cin>>l[i]>>r[i];
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	reverse(l.begin(),l.end());
	for (int i=0;i<n;++i)
	{
		int d=l[i]-r[i];
		if (d<=0) break;
		ans+=2*d;
	}
	cout<<ans;
	return 0;
}