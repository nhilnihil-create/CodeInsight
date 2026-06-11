#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int

ll a[MAXX];
multiset<ll> ms;
multiset<ll>::iterator it;
signed main()
{
    FAST;
    string s;
    ll k;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> k;
    for(ll i = 0; i <= 3; i++){
    	for(ll j = i+1; j <= 4; j++){
    		if(a[j] - a[i] > k){
    			cout << ":(";
    			return 0;
			}
		}
	}
	cout << "Yay!";
}