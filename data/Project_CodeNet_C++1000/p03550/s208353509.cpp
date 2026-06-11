	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	using namespace __gnu_pbds;
	using namespace std;
	#define mod 1000000007
	#define fi first
	#define se second
	#define mp make_pair
	#define pb push_back
	#define ps push
	#define pll pair<long,long>
	typedef long long ll;
	#define PI 3.14159265
	#define vi vector<pll> 
		 
	typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
	const ll INF=(ll)5e17;	
		
	long long binpow(long long a, long long b, long long m) {
			a %= m;
			long long res = 1;
			while (b > 0) {
				if (b & 1)
					res = res * a % m;
				a = a * a % m;
				b >>= 1;
			}
			return res;
	}

		
		
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		ll n,z,w;
		cin>>n>>z>>w;
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
		}
		if(n==1)
		{
			cout<<abs(w-v[0]);
		}
		else
		{
			cout<<max(abs(w-v[n-1]),abs(v[n-1]-v[n-2]));
		}
		
	}
