#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll yojo[10010];
bool f[10010];
int main(){
	ll n;
	cin>>n;
	vector<vector<ll>>ro(n+1);
	for(int i=0;i<n-1;i++){
		ll a,b;
		cin>>a>>b;
		ro[a].push_back(b);
		ro[b].push_back(a);
	}
	vector<ll>c;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		c.push_back(x);
	}
	sort(c.begin(),c.end(),greater<ll>());
	ll num;
	for(int i=1;i<=n;i++){
		if(ro[i].size()==1){
			num=i;
			break;
		}
	}
	queue<ll>que;
	que.push(num);
	f[num]=1;
	yojo[num]=c[0];
	ll ans=0,now=1;
	while(!que.empty()){
		ll x=que.front();
		que.pop();
		for(ll p:ro[x]){
			if(f[p])continue;
			f[p]=1;
			yojo[p]=c[now];
			ans+=c[now];
			now++;
			que.push(p);
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)cout<<yojo[i]<<' ';
	return 0;
}