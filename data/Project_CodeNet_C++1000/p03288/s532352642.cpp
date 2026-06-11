#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int a;
	cin>>a;
	if(a<1200)cout<<"ABC\n";
	else if(a<2800&&a>=1200)cout<<"ARC\n";
	else if(a>=2800)cout<<"AGC\n";
    return 0;
}
