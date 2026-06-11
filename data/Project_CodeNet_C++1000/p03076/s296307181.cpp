	#include <bits/stdc++.h>
	  #define endl "\n"
	  #define ll long long int
	  #define mod 1000000007
	  #define inf 1000000000000000001;
	  using namespace std;
	  int main()
	  {
	    //  #ifndef ONLINE_JUDGE
	    //  // for getting input from input.txt
	    //  freopen("input.txt", "r", stdin);
	    //  // for writing output to output.txt
	    //  freopen("output.txt", "w", stdout);
	    // #endif
	    std::ios::sync_with_stdio(false);
	    cin.tie(NULL);

	    int v[5],sum=0,rm=0,a[5];
	    for (int i = 0; i < 5; ++i)
	    {
	    	cin>>v[i];
	    	a[i] = v[i];
	    	while(v[i]%10 != 0){
	    		v[i]++;
	    	}
	    	rm = max(rm,v[i]-a[i]);

	    	sum += v[i];

	    	// cout<<sum<<endl;
	    }

	    cout<<v[0]+v[1]+v[2]+v[3]+v[4]-rm;
	    return 0;
	  }
