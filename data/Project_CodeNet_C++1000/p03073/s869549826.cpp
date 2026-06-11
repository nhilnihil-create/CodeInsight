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
    cin >> s;
    ll ans= 0, br = 0, zer = 0;
    for(ll i = 0; i < s.size(); i++){
    	zer = 0;
    	br = 0;
    	if(s[i] == s[i+1]) {
    			if(s[i+1] == '1'){
    				s[i+1] = '0';
				} 
				else{
					s[i+1] = '1';
				}
				ans ++;
			}
	}
	if(s.size() == 1){
		cout << 0;
		return 0;
	}
	
	cout << ans;
}