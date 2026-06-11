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
  	int y , m , d;
  	cin >> y >> m;
  	if( m%y == 0)
  		cout << y+m;
  	else
  		cout << m - y;
    return 0;
}
