#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

	typedef tree<
			int,
			null_type,
			less<int>,
			rb_tree_tag,
			tree_order_statistics_node_update>
	ordered_set;
	
#define ll long long 


int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	ll n;cin>>n;
	vector <ll> ans(n);
	for(int i=0;i<n;i++){
		cin>>ans[i];
	}
	for(int i=0;i<n;i++){
		ll temp;cin>>temp;
		ans[i]-=temp;
	}
	sort(ans.begin(),ans.end());
	ll val=0;
	for(int x:ans){
		if(x>0){
			val+=x;
		}
	}
	cout<<val<<endl;
	return 0;
	
}
