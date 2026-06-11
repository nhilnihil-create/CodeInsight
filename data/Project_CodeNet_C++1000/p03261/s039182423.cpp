#include <bits/stdc++.h>
#define int long long int
#define gif(a,b) (a/b +(a%b?1:0))
#define pi 3.14159265358
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n";
#define float long double
using namespace std;

int32_t main()
{   
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
  	int  x;
  	cin >> x;
  	string a[x];
  	for(int i = 0; i < x; ++i)
  	{
  		cin >> a[i];
  		if(i)
  		{
  			int n = a[i-1].length();
  			if(a[i][0] != a[i - 1][n-1])
  				{	
  				cout << "No";
  				return 0;
  				}
  		}
  		for(int l = 0; l < i; l++)
  		{
  			if(a[i] == a[l])
  			{	
  				cout << "No";
  				return 0;
  			}
  		}
  	}

  	cout << "Yes";
    return 0;
}
