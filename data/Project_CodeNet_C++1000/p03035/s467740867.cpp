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
ll n,b;
cin>>n>>b;

ll cost=b;
if(n>5&&n<=12)
{
	cost=b/2;
}
else if(n<=5)cost=0;

cout<<cost;

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

		
	
	
	
	
