#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
vector<int> nex[214514];
ll adeg[214514],bdeg[214514],alive[214514];
signed main(){
	int n,m;
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(x==y){
			nex[x].pb(x);
			if(str[x-1]=='A'){
				adeg[x]++;
			}
			else{
				bdeg[x]++;
			}
		}
		else{
			nex[x].pb(y);
			if(str[y-1]=='A'){
				adeg[x]++;
			}
			else{
				bdeg[x]++;
			}
			nex[y].pb(x);
			if(str[x-1]=='A'){
				adeg[y]++;
			}
			else{
				bdeg[y]++;
			}
		}
	}
	queue<int> que;
	for(int i=1;i<=n;i++){
		if(adeg[i] == 0 || bdeg[i]==0){
			que.push(i);
			alive[i] = -1;
		}
	}
	while(!que.empty()){
		int cur = que.front();que.pop();
		int aa = 0, bb = 0;
		if(str[cur-1]=='A')aa++; else bb++;
		for(int i=0;i<nex[cur].size();i++){
			int nx = nex[cur][i];
			if( adeg[nx] > 0 && bdeg[nx] > 0){
				adeg[nx] -= aa;
				bdeg[nx] -= bb;
				if( adeg[nx] == 0 || bdeg[nx] == 0){
					alive[nx] = -1;
					que.push(nx);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(alive[i]==0){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}