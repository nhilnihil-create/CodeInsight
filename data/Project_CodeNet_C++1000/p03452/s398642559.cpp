#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
ll used[114514];
vector< pair<ll,ll> > pat[114514];
int main(){
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll tl,tr,td;
		cin>>tl>>tr>>td;
		pat[tl].pb(mp(tr,td));
		pat[tr].pb(mp(tl,-td));
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			queue<ll> que;
			map<ll,ll> mp;
			que.push(i);
			mp[i] = mod;
			while(!que.empty()){
				ll cf = que.front();que.pop();
				if(used[cf]==0){
					//cout<<cf<<endl;
					used[cf]=1;
					for(int j=0;j<pat[cf].size();j++){
						ll cto = pat[cf][j].first;
						ll cdis = pat[cf][j].second;
						if( mp[cto] != 0 && mp[cto]!= mp[cf]+cdis){
							cout<<"No"<<endl;
							return 0;
						}
						else{
							mp[cto] = mp[cf]+cdis;
							que.push(cto);
						}
					}
				}
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}