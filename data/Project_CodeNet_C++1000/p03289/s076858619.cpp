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
  	
  	string s;
  	cin >> s;
  	int n = s.length();
  	int flag = 0 , flag2 = 0;
  	if(s[0] == 'A')
  		flag++;
  	for(int i = 1; i < n ; ++i)
  	{
  		if(!(s[i] == 67 || s[i] >= 97))
  		{
  			cout << "WA";
  			return 0;
  		}
	}
	if(s[n -1] == 67)
  		{
  			cout << "WA";
  			return 0;
  		}
	for(int i = 2; i < n - 1; ++i)
	if(s[i] == 67)
		flag2++; 	
	if(flag == 1 && flag2 == 1)
  	cout << "AC";
  	else 
  	cout << "WA";
    return 0;
}
