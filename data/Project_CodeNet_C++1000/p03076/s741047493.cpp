#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 200010
 
#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define F first
#define S second
 
#define ll 	long long 
 
#define mod  1000000007
 

 
int main()
{
	FAST;
	int a[7];
	int x = 0;
	int o = 0;
	for(int i = 0; i < 5; i ++){
		cin >> a[i];
		if(a[i] % 10){
			x = max(10 -  a[i]%10, x);
			
		}
		
	}
	int ans = 0;
	for(int i = 0; i < 5; i ++){
		
			ans += a[i];
			if(a[i]% 10 ){
				ans += 10;
			ans -= a[i]%10;
			}
			
		
	}
	ans -= x;
	cout << ans;
	return 0;
}