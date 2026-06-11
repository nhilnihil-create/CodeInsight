#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
char c[1010][1010];
int main(){
		ll h,w;
		cin>>h>>w;
		queue<pair<P,ll>>que;
		ll cnt=0;
		for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
			cin>>c[i][j];
			if(c[i][j]=='#'){
				cnt++;
				que.push({{i,j},1});
			}
		}
		if(cnt==h*w){
			cout<<0<<endl;
			return 0;
		}
		ll dy[4]={0,1,0,-1},dx[4]={1,0,-1,0};
		while(!que.empty()){
			pair<P,ll>p=que.front();
			que.pop();
			ll y=p.first.first,x=p.first.second;
			for(int i=0;i<4;i++){
				if(!(1<=y+dy[i]&&y+dy[i]<=h&&1<=x+dx[i]&&x+dx[i]<=w))continue;
				if(c[y+dy[i]][x+dx[i]]=='#')continue;
				c[y+dy[i]][x+dx[i]]='#';
				cnt++;
				if(cnt==h*w){
					cout<<p.second<<endl;
					return 0;
				}
				que.push({{y+dy[i],x+dx[i]},p.second+1});
			}
		}

	return 0;
}
