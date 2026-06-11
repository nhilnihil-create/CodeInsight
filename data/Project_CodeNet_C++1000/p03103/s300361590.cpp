#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n,m; cin>>n>>m;
	priority_queue<pair<ll,ll>> q;
	for(int i=0; i<n; i++){
		ll a,b;cin>>a>>b;
		q.push({-a,b});
	}
	ll sum{},now{};
	while(1){
		auto p = q.top();
		q.pop();
		if(p.second>=m-now){
			sum += -p.first*(m-now);
			break;
		}
		else{
			now += p.second;
			sum += -p.first*p.second;
		}
	}
	
	cout << sum<<endl;
	
}