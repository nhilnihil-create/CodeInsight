#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,m;
	cin >> n >> m;
	vector<pair<ll,ll>> v;
	for(ll i=0; i<n; i++){
		ll a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end(), comp);
	ll price = 0, count = 0;
	ll final1 = 0, final2 = 0;
	for(auto x:v){
		price += x.first*x.second;
		count += x.second;
		if(count >= m){
			final1 = x.first;
			final2 = x.second;
			break;
		}
	}
	cout << price - (count-m)*final1;
	return 0;

}