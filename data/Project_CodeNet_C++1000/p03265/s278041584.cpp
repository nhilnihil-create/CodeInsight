#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=c-a;
	int y=d-b;
	cout<<c-y<<' '<<d+x<<' '<<a-y<<' '<<b+x;
    return 0;
}
