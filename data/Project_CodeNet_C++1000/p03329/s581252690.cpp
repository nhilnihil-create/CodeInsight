#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e5+10;
int dis[maxn],vis[maxn],par[maxn];
int32_t main(){
	IOS
	for(int i=0;i<maxn;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	vector<int>dx;
	dx.push_back(1);
	for(int i=1;i*6<maxn;i*=6){
		dx.push_back(i*6);
	}
	for(int i=1;i*9<maxn;i*=9){
		dx.push_back(i*9);
	}
	dis[0]=0;
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
	pq.push({dis[0],0});
	while( pq.size() ){
		int u = pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(size_t i=0;i<dx.size();i++){
			if( u + dx[i] < maxn && dis[u+dx[i]] > dis[u] + 1){
				par[u+dx[i]]=u;
				dis[u+dx[i]]=dis[u]+1;
				pq.push({dis[u+dx[i]],u+dx[i]});
			}
			/*if( u - dx[i] >= 0   && dis[u-dx[i]] > dis[u] + 1){
				par[u-dx[i]]=u;
				dis[u-dx[i]]=dis[u]+1;
				pq.push({dis[u-dx[i]],u-dx[i]});
			}*/
		}
	}
	int n;cin>>n;
	cout<<dis[n];

	
 }
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
