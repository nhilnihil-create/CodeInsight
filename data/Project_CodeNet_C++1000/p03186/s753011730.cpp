#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll ans=b+min(a+b+1,c);
	cout<<ans<<endl;
}