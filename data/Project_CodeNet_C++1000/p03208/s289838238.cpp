#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n,k; cin>>n>>k;
	ll ans = 1e10;
	vector<int> h(n);
	for(auto &i:h) cin>>i;
	sort(h.begin(),h.end());
	for(int i=0; i+k-1<n; i++){
		ans = min<ll>(ans,h.at(i+k-1)-h.at(i));
	}
	cout <<ans<< endl;
}
