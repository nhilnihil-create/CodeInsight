#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <boost/multiprecision/cpp_int.hpp> 
#include <boost/math/constants/constants.hpp> 

#define ll long long

using namespace std;
using namespace __gnu_pbds;
using namespace boost::multiprecision; 

/// FInd by ordeer return ietrator to kth largest element.
/// Order of key numbers strictly less than k.

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> new_set;

int solve(std::vector<int> v,int n){
	std::vector<int> dp(n+1,0);
	dp[0] = 0;
	dp[1] = abs(v[1] - v[0]);
	for(int i = 2;i<n;i++){
		dp[i] = min(dp[i-1] + abs(v[i] - v[i-1]),dp[i-2] + abs(v[i] - v[i-2]));
	}
	return dp[n-1];
}

int main(){
	
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  int n;cin >> n;
  std::vector<int> v(n);
  for(int i = 0;i<n;i++){
  	cin >> v[i];
  }
  cout<<solve(v,n)<<endl;
  return 0;
}