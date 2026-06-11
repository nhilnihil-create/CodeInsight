    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	long long n,m=0;
    	cin>>n;
    	long long x,y,z;
    	vector<pair<long long,pair<long long,long long> > > v;
    	for(long long i=0;i<n;i++){
    	    cin>>x>>y>>z;
    	    m=max(m,y+x);
    	    v.push_back(make_pair(x+y,make_pair(x,z)));
    	}
    	sort(v.begin(),v.end());
    	long long dp[m+1]={0};
    	long long ans=0;
    	for(long long i=0;i<n;i++){
    	    for(long long j=v[i].first;j>=v[i].second.first;j--){
    	        dp[j]=max(dp[j],dp[j-v[i].second.first]+v[i].second.second);
    	        ans=max(dp[j],ans);
    	    }
    	}cout<<ans;
    	
    }