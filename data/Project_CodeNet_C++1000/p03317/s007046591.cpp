#include<bits/stdc++.h>

		using namespace std;

		int main()
		{ios_base::sync_with_stdio(false);
		    cin.tie(NULL);
		 	  int n,k;
		 	  cin>>n>>k;
		 	  int a[n];
		 	  for(int i=0;i<n;i++)
		 	  {
		 	  	cin>>a[i];
		 	  }
		 	  if(k==n)
		 	  {
		 	  	cout<<1<<endl;
		 	  }
		 	  else
		 	  {
		 	  	if((n-1)%(k-1)==0)cout<<(n-1)/(k-1);
    			else cout<<(n-1)/(k-1)+1<<endl;
		 	  }
			return 0;

		}