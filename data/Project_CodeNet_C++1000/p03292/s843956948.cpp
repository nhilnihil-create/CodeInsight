#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<max(max(a,b),c)-min(min(a,b),c);
    return 0;
}
