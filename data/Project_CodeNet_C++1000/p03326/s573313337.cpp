	/**
	*    author:  accesss_denied
	**/
	#include <bits/stdc++.h>
	using namespace std;
	#define ll long long int
	#define ff first
	#define ss second
	#define pb push_back
	#define endl "\n"
	#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll mod=1e9+7;			
	ll inf=1e18;
    ll bit[3]={0};

               

	int main() {
				fast
				// #ifndef ONLINE_JUDGE
				// freopen("input.txt","r",stdin);
				// freopen("output.txt","w",stdout);
				// #endif

				ll t;
				t=1;
				while(t--)
				{
					ll n,m;
					cin>>n>>m;
					vector<pair<pair<ll,ll>,ll>> arr;
					for(ll i=0;i<n;i++)
					{
                        ll a,b,c;
                        cin>>a>>b>>c;
                        arr.pb({{a,b},c});
                    }

                    ll ans=0;
                    for(ll k=0;k<8;k++)
                    {
                        for(ll j=0;j<=2;j++) bit[j]=0;
                        for(ll j=2;j>=0;j--)
                        {
                            if(k&(1<<j))
                            bit[j]=1;
                        }
                        vector<ll> temp;

                        for(ll i=0;i<n;i++)
                        {
                            ll arr2[3]{arr[i].ff.ff,arr[i].ff.ss,arr[i].ss};
                            for(ll j=0;j<3;j++)
                            {
                                if(bit[j]==0)
                                arr2[j]=-arr2[j];
                            }
                            temp.pb(arr2[0]+arr2[1]+arr2[2]);
                        }
                        sort(temp.rbegin(),temp.rend());
                        ll ans2=0;
                        for(ll i=0;i<m;i++)
                        ans2+=temp[i];
                        ans=max(ans,ans2);
                    }
                    cout<<ans<<endl;
					
				}
				return 0;
			}	


