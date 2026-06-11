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
  	char a , b;
  	string s;
  	cin >> s;
    stringstream ss(s);
    ss >> y >> a >> m >> b >> d;
    int flag = 0;
    if(y > 2019)
    	flag = 1;
    else if(y == 2019 && m > 04)
    	flag = 1;
  	if(flag == 1)
  		cout << "TBD";
  	else
  		cout <<"Heisei";
    return 0;
}
