    #include"bits/stdc++.h"
    using namespace std;
    typedef long long ll;
    #define int ll
    const int N=1e5+4;
    vector<bool> prime(N,1);
    vector<int> spec(N,0);
    int32_t main()
    {
    	#ifndef ONLINE_JUDGE
    	freopen("in","r",stdin);
    	freopen("out","w",stdout);
    	#endif
    	
    	int n;
    	cin>>n;
    	vector<int>a(n),b(n),c(n);
    	for(auto &i:a)cin>>i;
    	for(auto &i:b)cin>>i;
    	for (int &i:c)cin>>i;
     
    	sort(a.begin(),a.end());
    	sort(b.begin(),b.end());
    	sort(c.begin(),c.end());
     
     
    	int ans=0;
     
    	for(int i=0;i<n;i++)
    	{
     
    		int l=lower_bound(a.begin(),a.end(),b[i])-a.begin();
    		int r=n-(upper_bound(c.begin(),c.end(),b[i])-c.begin());
    		ans+=l*r;
    	}
     
    	cout<<ans;
     
    	
     
     
     
     
    	
    }