#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))

ll bit[200010];
ll n;

void update(ll idx, ll val) {
	ll i;
    for(i=idx;i<=n;){
    	bit[i]=max(bit[i],val);
    	i += i&(-i);
    }
}

ll query(ll idx) 
{
	ll i,val=-1;
	for(i=idx;i>0;){
		val=max(val,bit[i]);
		i -= i&(-i);
	}
	return val;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i;
    cin>>n;
    vector<pair<ll,ll>>v;
    ll h[n],val[n];
    for(i=0;i<n;i++){
    	cin>>h[i];
    	v.push_back({h[i],i});
    }
    for(i=0;i<n;i++){
    	cin>>val[i];
    }
    sort(v.begin(),v.end());
    mem(bit,0);
    ll ans=0;
    for(i=0;i<n;i++){
    	ll temp = val[v[i].second]+query(v[i].second+1);
    	ans=max(ans,temp);
    	update(v[i].second+1,temp);
    }
    cout<<ans;
    return 0;
}