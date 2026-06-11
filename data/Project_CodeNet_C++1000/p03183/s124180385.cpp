#include <bits/stdc++.h>
//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//~ using namespace __gnu_pbds; 
#define mp make_pair
#define endl '\n'
typedef long long ll;
 
const int INF=1e9+5;
const ll lim=(ll)3e16;
const int N=2e4+5;
const int mod=1e9+7;	
const ll oo=1e18+5;

//~ typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct block{
	int w,s,val;
	void read(){
		cin>>w>>s>>val;
	}
	bool operator<(const block& b) const{
		return w+s<b.w+b.s;
	}
};

//~ ll dp[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	int n;
	cin>>n;
	vector<block> b(n);
	int max_block=0;
	for(int i=0;i<n;++i){
		b[i].read();
		max_block=max(max_block,b[i].s+b[i].w);
	}
	sort(b.begin(),b.end());
	vector<ll> dp(max_block+1);
	ll ans=0;
	// dp[i] is the best of boxes with total weight i
	for(int i=0;i<n;++i){
		for(int j=b[i].s;j>=0;--j){
			dp[j+b[i].w]=max(dp[j+b[i].w],dp[j]+b[i].val);
			//~ cout<<ans<<endl;
			ans=max(ans,dp[j+b[i].w]);
		}
	}
	cout<<ans;
	return 0;	
}
