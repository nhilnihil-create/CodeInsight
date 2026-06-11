#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll n,k;vector<ll>ch[100010];
bool ans[100010];
void dep(ll now,ll s){
	if(now!=s&&ch[now].size()==1){
		return ;
	}
	for(ll i=0;i<ch[now].size();i++){
		ll next=ch[now][i];
		if(ans[next]==true){
			continue;
		}
		ans[next]=true;
		dep(next,s);
	}
}
int main() {
	cin>>n>>k;
	for(ll i=0;i<k;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		x--;y--;
		ch[x].push_back(y);
		ch[y].push_back(x);
	}
	ll ans2=0;
	for(ll i=0;i<n;i++){
		if(ans[i]==true){
			continue;
		}
		ans2++;
		dep(i,i);
	}
	cout <<ans2;
	// your code goes here
	return 0;
}