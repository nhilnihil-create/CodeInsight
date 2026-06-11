#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int a,b;
	cin>>a>>b;
	int ans=max(a,b)*2;
	if(a!=b)ans--;
	cout<<ans<<endl;
    return 0;
}
