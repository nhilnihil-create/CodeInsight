#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000
#define mod 1000000007
#define pll pair<long,long>
#define se second
#define fi first
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>pllordered_set;


int main()
{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
			ll n;
			cin>>n;
			vector<ll> v(n);
			map<ll,ll> m;
			for(ll i=0;i<n;i++)
				{cin>>v[i];m[v[i]]++;}
			ll ans=0;
			sort(v.begin(),v.end(),greater<int>());
			for(ll i=0;i<n;i++)
			{
				if(!m[v[i]])
					continue;
				ll val=0;
				ll v1=v[i];
				ll cnt=0;
				while(v1%2==0)
				{
					v1/=2;
					cnt++;
				}
				val+=(1<<cnt);
				while(v1>0)
				{
					if(v1%2==0)
						val+=(1<<cnt);
					cnt++;
					v1/=2;
				}
				m[v[i]]--;
				if(m[val])
				{
				
					m[val]--;
				//	cout<<val<<" "<<v[i]<<endl;
					ans+=1;
				}
				
			}
			cout<<ans;
			
			
			
}
