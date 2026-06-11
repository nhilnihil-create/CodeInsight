#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b;
	cin>>c>>d;
	int ans =(a*b)-((c*b)+((a-c)*d));
	cout<<ans<<endl; 
	return 0;
}