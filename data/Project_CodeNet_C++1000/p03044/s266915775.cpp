#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll n;
vector<pair<ll,ll>>ch[100010];
ll ans[100010];
void dep(ll now,ll c){
	if(now!=0&&ch[now].size()==1){
		return ;
	}
	for(ll i=0;i<ch[now].size();i++){
		ll next=ch[now][i].first;
		if(ans[next]!=-1){
			continue;
		}
		ll co=ch[now][i].second;
		if(co%2==0){
			ans[next]=c;
			dep(next,c);
		}
		else{
			ans[next]=abs(c-1);
			dep(next,ans[next]);
		}
	}
}
int main() {
	cin>>n;
	for(ll i=0;i<n;i++){
		ans[i]=-1;
	}
	for(ll i=0;i<n-1;i++){
		ll x,y,c;
		cin>>x>>y>>c;
		x--;y--;
		ch[x].push_back(make_pair(y,c));
		ch[y].push_back(make_pair(x,c));
	}
	ans[0]=0;
	dep(0,0);
	for(ll i=0;i<n;i++){
		cout <<ans[i]<<endl;
	}
	// your code goes here
	return 0;
}