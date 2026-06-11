#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int t;
	double s1 = 0, s2 = 0;
	cin >> t;
	for(int i = 0 ; i < t; i++){
		double a;
		string x;
		cin >> a >> x;
		
		if(x == "BTC"){
			s1 += a;
		}
		else if(x == "JPY"){
			s2 += a;
		}
		
		
	}
	printf("%0.4lf\n",(s1*380000)+s2);
	return 0;
}