#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll cnt[15];
int main(){
	ll n;
	cin>>n;
	bool f=0;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		cnt[x]++;
		if(cnt[x]==3||x==0)f=1;
	}
	if(f)cout<<0<<endl;
	else{
		vector<ll>v,w;
		v.push_back(0ll);
		for(int i=1;i<=12;i++){
			if(cnt[i]==2){
				v.push_back(i);
				w.push_back(24-i);
			}else if(cnt[i]==1)w.push_back(i);
		}
		// for(auto x:v)cout<<x<<' ';
		// cout<<endl;
		// for(auto x:w)cout<<x<<' ';
		// cout<<endl;
		ll ans=0;
		for(int i=0;i<(1<<w.size());i++){
			vector<ll>num=v;
			for(int j=0;j<w.size();j++){
				if(i&(1<<j))num.push_back(w[j]);
				else num.push_back(24-w[j]);
			}
			num.push_back(24);
			sort(num.begin(),num.end());
			ll mi=1e9;
			for(int j=1;j<num.size();j++)mi=min(mi,num[j]-num[j-1]);
			ans=max(ans,mi);
		}
		cout<<ans<<endl;
	}
	return 0;
}
