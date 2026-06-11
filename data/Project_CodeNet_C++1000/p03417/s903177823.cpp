#include <bits/stdc++.h>
#define int long long
using namespace std;

int a,b; 

signed main()
{
	cin>>a>>b;
	
	if (a==1&&b==1)  cout<<1<<endl;
	else if (a==1&&b!=1)  cout<<b-2<<endl;
	else if (b==1&&a!=1)  cout<<a-2<<endl;
	else cout<<(a-2ll)*(b-2ll)<<endl;
	
	return 0;
}