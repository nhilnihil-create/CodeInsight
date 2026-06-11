#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
		tree_order_statistics_node_update> indexed_multiset;



int n;

int main(){	
	cin>>n;
	vector<int>vi;
	int mxn = 0 , mn = 1e8 , plmn = -1 , plmxn = -1;
	for(int i = 0; i< n ; i++){
		int x ; cin>>x;
		vi.push_back(x);
		if(x < mn){
			mn = x;
			plmn = i;
		}if(x >mxn){
			mxn = x;
			plmxn = i;
		}
	}
	vector<pair<int,int>>ans;
	if(abs(mxn) > abs(mn)){
		//0 --- > n
	for(int i =0 ; i < n ; i++){
		ans.push_back({plmxn+1,i+1});
		vi[i]+=vi[plmxn];
	}
	//0---->n-1
	for(int i = 0; i < n - 1 ;i++){
		ans.push_back({i+1 , i+2});
		vi[i+1]+=vi[i];
	}
	}//mxn<mn i -- > n
	// n-1 -- > i
	else{
		for(int i = 0; i <n ; i++){
			ans.push_back({plmn+1,i+1});
			vi[i]+=vi[plmn];
		}
		for(int i = n-1 ; i>= 1 ; i--){
			ans.push_back({i+1,i});
			vi[i-1]+=vi[i];
		}
	}
	//for(int i =0 ;i < n ; i++)cout<<vi[i]<<" ";
	cout<<(int)ans.size()<<endl;
	for(int i = 0; i < (int)ans.size() ; i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
    return 0;
}
