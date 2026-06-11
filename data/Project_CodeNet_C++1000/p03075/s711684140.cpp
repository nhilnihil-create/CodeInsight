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
	    // int a,b,c,d,e,k;
	    // cin>>a>>b>>c>>d>>e>>k;
	    int v[6];
	    for (int i = 0; i < 6; ++i)
	    {
	    	cin>>v[i];
	    }
	    // cout<<v[5];
	    for (int i = 0; i < 4; ++i)
	    {
	    	for (int j = 1; j < 5; ++j)
	    	{
	    		if(abs(v[i]-v[j]) > v[5]){
	    			// cout<<abs(v[i]-v[j]);
	    			cout<<":(";
	    			return 0;
	    		}
	    	}
	    }

	    cout<<"Yay!";

	    return 0;
	  }
