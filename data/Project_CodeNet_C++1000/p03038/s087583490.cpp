#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <iomanip>
#include <stack>
#include <unordered_set>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e14, flag,cnt;

ll check(ll arr[],ll n,ll key){ 
    ll left = 0; 
    ll right = n - 1;
    ll count = 0; 
    while (left <= right) { 
        ll mid = (right + left) / 2;
        if (arr[mid] < key) { 
            count = mid + 1; 
            left = mid + 1; 
        }
        else
            right = mid - 1; 
    } 
    return count; 
} 



int main(){
	ll n,m;
	cin>>n>>m;
	ll a[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	
	vector<pair<ll,ll>> v;
	for(ll i=0; i<m; i++){
		ll a,b;
		cin>>a>>b;
		v.push_back(make_pair(b,a));
	}
	sort(a,a+n);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	map<ll,ll> mp;
	
	for(ll i=0; i<m; i++){
		ll h=check(a,n,v[i].first);
		mp[v[i].first]=h;
	}
	for(ll i=0; i<n; i++){
		if(a[i]>=v[0].first) sum+=a[i];
	}
	for(ll i=0; i<m; i++){
		ll g= mp[v[i].first]-cnt;
		ll k=min(v[i].second,g);
		ll f=max(k,0ll);
		cnt+=f;
		sum+=v[i].first*f;
	}
	for(ll i=cnt; i<mp[v[0].first]; i++){
		sum+=a[i];
	}
	cout<<sum;
}
