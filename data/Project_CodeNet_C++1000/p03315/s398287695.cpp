#include<bits/stdc++.h>

		using namespace std;

		int main()
		{ios_base::sync_with_stdio(false);
		    cin.tie(NULL);
		 	  string s;
		 	  cin>>s;
		 	  int ans=0;
		 	  for(auto i:s)
		 	  {
		 	  	if(i=='+')
		 	  		ans++;
		 	 	else
		 	 		ans--;
		 	  }
		 	  cout<<ans<<endl;
			return 0;

		}