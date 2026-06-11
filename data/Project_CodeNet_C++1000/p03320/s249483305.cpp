#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll k;
	cin>>k;
	ll c=1;
	ll df = 1;
	while(k)
	{
		cout<<c<<"\n";
		k--;
		while(1)
		{
			ll ck = c + df;
			ll t=ck;
			ll sk=0;
			while(t)
			{
				sk = sk+t%10;
				t/=10;
			}
			ll ck2 = c + 10*df;
			t=ck2;
			ll sk2 = 0;
			while(t)
			{
				sk2 = sk2+t%10;
				t/=10;
			}
			if(ck*sk2<ck2*sk)
			{
				c = ck;
				break;
			}
			else
			{
				df *= 10;
			}
		}
	}
	return 0;
}