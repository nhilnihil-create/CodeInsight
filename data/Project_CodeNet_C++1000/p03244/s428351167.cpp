#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007
 
vector<int> v1(MAXX);
vector<int> v2(MAXX);
 
int main()
{
	FAST;
	ll n;
	cin >> n;
	ll x;
	for(ll i = 1; i <= n; i ++){
		cin >> x;
		if(i % 2){
			v1[x] ++;
		}
		else{
			v2[x] ++;
		}
	}
	vector< pair <int , int> > v3; 
	vector< pair <int , int> > v4;
	for(ll i = 1; i <= 100000; i ++){
		if(v1[i]){
			v3.push_back({v1[i], i});
		}
		if(v2[i]){
			v4.push_back({v2[i], i});
		}
	}
	if(v3.size() == 1){
		v3.push_back({0, 0});
	}
	if(v4.size() == 1){
		v4.push_back({0, 0});
	}
	sort(v3.begin() , v3.end());
    reverse(v3.begin() , v3.end());
    sort(v4.begin() , v4.end());
    reverse(v4.begin() , v4.end());
    ll ans = 0;
    ll a = v3[0].F;
    ll b = v3[0].S;
    ll c = v3[1].F;
    ll d = v3[1].S;
    ll e = v4[0].F;
    ll f = v4[0].S;
    ll g = v4[1].F;
    ll h = v4[1].S;
    if(b != f){
    	ans = n - a - e;
	}
	else{
		ans = min(n - a - g, n - c - e);
	}
	cout << ans;
	return 0;
}