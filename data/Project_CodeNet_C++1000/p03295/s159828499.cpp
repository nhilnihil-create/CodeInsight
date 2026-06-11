#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
P p[114514];
int main(){
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>p[i].second>>p[i].first;
	}
	sort(p,p+m);
	ll ans=0;
	ll now=-1;
	for(int i=0;i<m;i++){
		if(p[i].second>now){
			ans++;
			now=p[i].first-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}