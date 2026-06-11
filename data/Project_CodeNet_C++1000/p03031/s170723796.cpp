#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
ll n,m,li[12],sw[12],ans;
vector<ll>ch[12];
void cal(){
	for(ll i=0;i<m;i++){
		ll cnt=0;
		for(ll j=0;j<ch[i].size();j++){
			if(sw[ch[i][j]]==1){
				cnt++;
			}
		}
		if(cnt%2!=li[i]){
			return ;
		}
	}
	ans++;
	return ;
}
void dep(ll now){
	if(now==n){
		cal();
		return ;
	}
	sw[now]=0;dep(now+1);
	sw[now]=1;dep(now+1);
}
int main() {
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll k;
		cin>>k;
		for(ll j=0;j<k;j++){
			ll x;
			cin>>x;
			x--;
			ch[i].push_back(x);
		}
	}
	for(ll i=0;i<m;i++){
		cin>>li[i];
	}
	dep(0);
	cout <<ans;
	// your code goes here
	return 0;
}