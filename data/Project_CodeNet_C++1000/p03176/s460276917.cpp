#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define sorted(a_1) sort(a_1.begin(),a_1.end())
#define rsorted(a_1) sort(a_1.rbegin(),a_1.rend())
#define t1(a_1) cout<<a_1<<endl;
#define t2(a_1) for(auto it_test : a_1) cout<<it_test<<" ";

ll bittree[1000001];
void update(ll index,ll n, ll val){
	for(ll i=index;i<=n;){
		bittree[i] = max(bittree[i],val);
		i += i & (-i);
	}
}

ll get(ll u, ll n){
	ll index = u;
	ll sum = 0;
	for(ll i=index;i>0;){
		sum = max(bittree[i],sum);
		i -= i & (-i);
	}
	return sum;
}

void solve(){
	ll n;
	cin>>n;
	vector<ll>height(n),val(n);
	vector<pair<ll,ll>>pair;
	for(ll i=0;i<n;i++){
	   	cin>>height[i];
	   	pair.pb({height[i],i});
	}
	for(auto &i : val) cin>>i;
	sorted(pair);
	memset(bittree,0,sizeof(bittree));
	ll ans = 0;
	for(ll i=0;i<n;i++){
		ll res = val[pair[i].second] + get(pair[i].second+1,n);
		ans = max(ans,res);
		update(pair[i].second+1,n,res);
	}
	ans = max(ans,get(n,n));
	// t2(bittree)
	// t1(endl)
	t1(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		solve();
	}

return 0;
}