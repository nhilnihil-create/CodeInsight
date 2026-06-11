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
	    int n;
	    cin>>n;
	    auto s = to_string(n);
	    // stos(s);
	    for (int i = 0; i <= 2; ++i)
	    {
	    	/* code */
	    	if(s[i] == '9'){
	    		s[i] = '1';
	    	}
	    	else if(s[i] == '1'){
	    		s[i] = '9';
	    	}
	    }
	    cout<<stoi(s);
	    return 0;
	  }
