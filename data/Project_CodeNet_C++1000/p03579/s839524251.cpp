#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
ll iro[114514],cc[3];
vector<ll> pat[114514];
signed main(){
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	for(ll i=0;i<m;i++){
		ll ta,tb;
		cin>>ta>>tb;
		pat[ta].pb(tb);
		pat[tb].pb(ta);
	}
	queue<ll> que;
	que.push(1);
	iro[1]=1;
	cc[1]++;
	while(!que.empty()){
		ll cx = que.front();que.pop();
		for(ll i=0;i<pat[cx].size();i++){
			ll cy = pat[cx][i];
			if(iro[cy]==0){
				iro[cy]=3-iro[cx];
				cc[iro[cy]]++;
				que.push(cy);
			}
			else if(iro[cx]+iro[cy]!=3){
				cout<<n*(n-1)/2 - m<<endl;
				return 0;
			}
		}
	}
	cout<<cc[1]*cc[2]-m<<endl;
	return 0;
}