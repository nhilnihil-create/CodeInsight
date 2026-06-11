#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
const ll MAX=1e5+5;

ll lcm(ll x,ll y)
{
	return ((x*y)/ __gcd(x,y));
}
void test_cases()
{
ll r,d,x;
cin>>r>>d>>x;

for(ll i=1;i<=10;i++)
{
	x=r*x-d;
	cout<<x<<"\n";
}

}

int main()
{
    fast;
	
	ll t;
//	cin>>t;
	t=1;
	while(t--)
	test_cases();





    
}

		
	
	
	
	
