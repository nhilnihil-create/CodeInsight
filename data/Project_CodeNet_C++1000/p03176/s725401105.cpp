#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> h(n+1);
	vector<int> b(n+1);
	for(int i=0;i<n;i++){
	    cin>>h[i+1];
	}
	for(int i=0;i<n;i++){
	    cin>>b[i+1];
	}
	map<long,long> map;
	vector<long> dp(n+1,0);
	dp[1] = b[1];
	map[h[1]] = dp[1];
	long ans = dp[1];
	for(int i=2;i<=n;i++){
	    dp[i] = b[i];
	    auto it = map.lower_bound(h[i]+1);
	    if(it!=map.begin()){
	        it--;
	        dp[i] += it->second;
	    }
	    map[h[i]]=dp[i];
	    it = map.upper_bound(h[i]);
	    while(it!=map.end()&&it->second<=dp[i]){
	        auto temp = it;
	        temp++;
	        map.erase(it);
	        it=temp;
	    }
	    
	    ans = max(ans,dp[i]);
	}
	cout<<ans<<'\n';
	
	return 0;
}