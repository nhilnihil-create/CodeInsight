#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	int n,k; cin>>n>>k;
	deque<ll> d;
	for(int i=0; i<n; i++){
		int v; cin >> v;
		d.push_back(v);
	} 
	ll ans{};
	for(int l=0; l<=min(k,n); l++){
		for(int r=0; r+l<=min(k,n); r++){
			auto d1 = d;
			int rm = k-(r+l);
			vector<int> po, ne;
			for(int i=0; i<l; i++){
				if(d.front()>=0){
					po.push_back(d.front());
					d.pop_front();
				}
				else{
					ne.push_back(d.front());
					d.pop_front();
				}
			}
			for(int i=0; i<r; i++){
				if(d.back()>=0){
					po.push_back(d.back());
					d.pop_back();
				}
				else{
					ne.push_back(d.back());
					d.pop_back();
				}
			}
			if(ne.size())sort(ne.rbegin(),ne.rend());
			for(int i=0; i<rm; i++){
				if(ne.size()){
					ne.pop_back();
				}
			}
			ll sum{};
			for(auto i:po) sum += i;
			for(auto i:ne) sum += i;
			ans = max(sum,ans);
			d = d1;
		}
	}
	cout << ans << endl;
	
}
