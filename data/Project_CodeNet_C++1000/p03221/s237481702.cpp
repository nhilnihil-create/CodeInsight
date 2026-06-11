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
#include <map>
#include <iterator>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e14, cnt;


ll a[1000001];
int main(){
	ll n,m;
	cin>>n>>m;
	ll p[m],y[m];
	vector<pair<ll,ll>> v;
	
	map<ll,ll> id;
	
	for(ll i=0; i<m; i++){
	
		cin>>p[i]>>y[i];
		v.push_back(make_pair(p[i],y[i]));
	}
	sort(v.begin(),v.end());
	for(ll i=0; i<m; i++){
		id[v[i].second]=a[v[i].first]+1;
		a[v[i].first]++;
	}
	for(ll i=0; i<m; i++){
		string s=to_string(p[i]);
		ll k=6-s.size();
		string s2=to_string(id[y[i]]);
		ll k2=6-s2.size();
		for(ll j=1; j<=k; j++) cout<<0;
		cout<<s;
		for(ll j=1; j<=k2; j++) cout<<0;
		cout<<id[y[i]]<<endl;
	}
	
}
