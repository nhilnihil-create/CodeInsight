	#include <bits/stdc++.h>
	  #define endl "\n"
	  #define ll long long int
	  #define mod 1000000007
	  #define inf 1000000000000000001;
	  using namespace std;
	  int main()
	  {
	    // #ifndef ONLINE_JUDGE
	     // for getting input from input.txt
	    // freopen("input.txt", "r", stdin);
	     // for writing output to output.txt
	    // freopen("output.txt", "w", stdout);
	   // #endif
	    std::ios::sync_with_stdio(false);
	    cin.tie(NULL);
	    ll n,v[5],m=inf;
	    cin>>n;
	    for (int i = 0; i < 5; ++i)
	    {
	    	cin>>v[i];
	    	m = min(v[i],m);
	    }
	    // cout<<n<<m;
	    cout<<(n-1)/m+5;
	    return 0;
	  }
