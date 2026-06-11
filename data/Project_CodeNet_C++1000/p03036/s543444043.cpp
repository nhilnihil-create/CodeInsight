#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int r,d,x,y;
	cin>>r>>d>>x;
	for(int i=0;i<10;i++)
	{
		y=x*r-d;
		x=y;
		cout<<y<<endl;
	}
    return 0;
}
