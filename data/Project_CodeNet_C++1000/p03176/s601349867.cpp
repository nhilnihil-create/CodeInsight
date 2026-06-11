#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 1<<30;
const ll MOD = 1e9+7;

vector<ll> tree;
int n;

int st_idx(){
	int l = ceil(log2(n));
	int idx = pow(2, l);
	return idx;
}

void upd(int k, ll x){
	k += st_idx();
	tree[k] = x;
	k/=2;
	while(k!=0){
		tree[k] = max(tree[2*k], tree[2*k+1]);
		k/=2;
	}
}

void build(vector<ll> arr){
	int sz = st_idx()*2;
	tree.assign(sz, 0);
	for(int i=0;i<arr.size();i++){
		upd(i, arr[i]);
	}
}

ll rmq(int l, int r){
	l += st_idx(); r += st_idx();
	ll ans = 0;
	while(l<=r){
		if(l%2 == 1)
			ans = max(ans, tree[l++]);
		if(r%2 == 0)
			ans = max(ans, tree[r--]);
		l/=2; r/=2;
	}
	return ans;
}

int main(){
	vector<pair<int, int> > h;
	vector<ll> dp;
	vector<ll> a;

	cin>>n;
	a.assign(n, 0);
	h.assign(n, {0, 0});
	dp.assign(n, 0);
	build(dp);

	for(int i=0;i<n;i++){
		cin>>h[i].first;
		h[i].second = i;
	}
	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(h.rbegin(), h.rend());

	for(int i=0;i<n;i++){
		int ht = h[i].first;
		int idx = h[i].second;
		ll maxi = rmq(idx, n-1);
		/*for(int j=idx;j<n;j++)
			maxi = max(maxi, dp[j]);*/
		upd(idx, maxi+a[idx]);
		dp[idx] = maxi+a[idx];
	}
	
	ll ans = 0;
	for(int i=0;i<n;i++)
		//cout<<i<<" : "<<dp[i]<<"\n";
		ans = max(ans, dp[i]);

	cout<<ans<<"\n";
	
	return 0;
}