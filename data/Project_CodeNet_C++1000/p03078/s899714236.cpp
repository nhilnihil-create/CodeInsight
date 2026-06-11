	#include <bits/stdc++.h>
	  #define endl "\n"
	  #define ll long long int
	  #define mod 1000000007
	  #define inf 1000000000000000001;
	  using namespace std;
	  ll x, y, z, k, a[1009], b[1009], c[1009];
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
	    // ll x,y,z,k;
	    cin>>x>>y>>z>>k;
	   	// vector<ll> a;
	   	// vector<ll> b;
	   	// vector<ll> c;
	   	vector<ll> v;
	   	// cout<<x<<y<<z<<k;
	   	for (int i = 0; i < x; ++i)
	   	{
	   		cin>>a[i];
	   	}

	   	sort(a, a + x, greater<ll>());
	   
	   	for (int i = 0; i < y; ++i)
	   	{
	   		cin>>b[i];
	   	}

	   	sort(b, b + y, greater<ll>());
	   	for (int i = 0; i < z; ++i)
	   	{
	   		cin>>c[i];
	   	}

	   	sort(c, c + z, greater<ll>());
	   	// cout<<"Hi";
	   	// for (int i = 0; i < x; ++i)
	   	// {
	   	// 	cout<<c[i]<<" ";
	   	// }

	   	for (int i = 0; i < x; ++i)
	   	{
	   		for (int j = 0; j < y; ++j)
	   		{
	   			for (int l = 0; l < z; ++l)
	   			{
	   				if( (i+1)*(j+1)*(l+1) <= k){
	   					v.push_back(a[i]+b[j]+c[l]);
	   				}
	   				else{
	   					break;
	   				}
	   			}
	   		}
	   	}
	   	sort(v.begin(), v.end(), greater<ll>());
	   	for (int i = 0; i < k; ++i)
	   	{
	   		cout<<v[i]<<endl;
	   	}
	    return 0;
	  }
