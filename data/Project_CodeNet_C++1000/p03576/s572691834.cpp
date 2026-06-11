#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N,K;
vector<pair<ll, ll>>v;

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		ll x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	ll ans=4*1000000000000000000;
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			int num=j-i+1;
			if(num<K)continue;
			vector<ll>y;
			for(int k=i;k<=j;k++){
				y.push_back(v[k].second);
			}
			sort(y.begin(),y.end());
			ll ydis=10000000000;
			for(int k=0;k<=y.size()-K;k++){
				ydis=min(ydis,y[k+K-1]-y[k]);
			}
			ll xdis=v[j].first-v[i].first;
			ans=min(ans,xdis*ydis);
		}
	}
	cout<<ans<<endl;
	return 0;
}