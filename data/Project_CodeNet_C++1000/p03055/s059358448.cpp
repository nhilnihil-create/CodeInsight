#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
vector<int> pat[214514];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		pat[a-1].pb(b-1);
		pat[b-1].pb(a-1);
	}
	vector<int> u1,u2,d1,d2;
	for(int i=0;i<n;i++){
		u1.pb(0);
		u2.pb(0);
		d1.pb(inf);
		d2.pb(inf);
	}
	queue<int> que;
	que.push(0);
	d1[0]=0;
	u1[0]=1;
	while(!que.empty()){
		int cur = que.front(); que.pop();
		for(int i=0;i<pat[cur].size();i++){
			if(u1[ pat[cur][i] ] == 0){
				u1[ pat[cur][i] ] = 1;
				d1[ pat[cur][i] ] = d1[cur] + 1;
				que.push( pat[cur][i] );
			}
		}
		//cout<<1<<endl;
	}
	vector< pair<int,int> > pv;
	for(int i=0;i<n;i++){
		pv.pb(mp(d1[i], i));
	}
	sort(pv.begin(),pv.end());
	reverse(pv.begin(),pv.end());
	int nexst = pv[0].second;
	//cout<<pv[0].first<<" "<<pv[0].second<<endl;
	queue<int> que2;
	que2.push(nexst);
	d2[nexst]=0;
	u2[nexst]=1;
	while(!que2.empty()){
		int cur = que2.front(); que2.pop();
		for(int i=0;i<pat[cur].size();i++){
			if(u2[ pat[cur][i] ] == 0){
				u2[ pat[cur][i] ] = 1;
				d2[ pat[cur][i] ] = d2[cur] + 1;
				que2.push( pat[cur][i] );
			}
		}
		//cout<<2<<endl;
	}
	for(int i=0;i<n;i++){
		//cout<<"d"<<i<<" "<<d2[i]<<endl;
	}
	sort(d2.begin(),d2.end());
	reverse(d2.begin(),d2.end());
	int lgst = d2[0];
	if((lgst%3)!=1)cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}