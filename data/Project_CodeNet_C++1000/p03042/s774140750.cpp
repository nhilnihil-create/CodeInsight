#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int

ll t , n, a[MAXX], b[MAXX], c[MAXX];

signed main()
{
	FAST;
	cin >> n;
	ll ay = n/100, il = n%100;
	if(ay >= 1 && ay <= 12){
		if(il >= 1 && il <= 12){
			cout << "AMBIGUOUS";
		}
		else{
			cout << "MMYY";
		}
		return 0;
	}
	else{
		if(il >= 1 && il <= 12){
			cout << "YYMM";
		}
		else cout << "NA";
	}
	
}