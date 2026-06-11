#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#define ll long long

using namespace std;

ll q,a,b; 

int main()
{
	int q;
	cin >> q;
	for (int query = 0; query < q; ++query)
	{
		ll a, b;
		cin >> a >> b;
		if (a > b)
		{
			swap(a, b);
		}
 
		ll ans = 0;
 
		if (a == 1 && b == 1)
		{
			ans = 0;
		}
		else
		{
 
			ll c = a*b - 1;
			ll x = sqrt(c) + 100;
 
			while (x*x>c)
			{
				x--;
			}
 
 
 
 
 
 
			ans = x * 2;
 
			if (x == c / x)
			{
				ans--;
			}
 
			if (x >= a)
			{
				ans--;
			}
 
			// BEGIN CUT HERE
//			cerr << "a=" << a << " b=" << b << " c=" << c << " x=" << x << " c/x=" << c/x << " ans=" << ans << endl;
			// END CUT HERE
 
 
 
		}
 
 
 
 
		cout << ans << endl;
	}
 
 
 
 
	return 0;
}

// int main(){
	
// 	cin>>q;
// 	while(q){
// 		cin>>a>>b;
// 		if(a==1&&b==1){
// 			cout<<0<<endl;
// 			return 0;
// 		}
// 		ll min1=min(a,b);
// 		ll x=sqrt(a*b)+100;
// 		while(x*x>(a*b)-1)x--;
// 		ll ans=2*x;
// 		if(x>=min1)ans--;
// 		if(x==((a*b)-1)/x)ans--;
// 		cout<<ans<<endl;

// 		q--;
// 	}


// 	return 0;
// }

