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

const int dx[4] = {+1,-1,+0,-0};
const int dy[4] = {+0,-0,+1,-1};
const int maxn = 55;
vector<string>s(maxn);
int n,m;
bool valid(int x,int y){
	return x >=0 && x < n && y >=0 && y < m;
}
int spfa(int source){
	//return 0;
	vector<int>dis(n*m,1e8),inq(n*m);
	queue<int>q;
	dis[source]=0;
	q.push(source);
	inq[source]=1;
	while( q.size() ){
		int u = q.front(); q.pop(); inq[u] = 0;
		for(int k=0;k<4;k++){
			int x = u/m + dx[k];
			int y = u%m + dy[k];
			if( valid(x,y) && s[x][y] != '#' && dis[x*m+y] > dis[u] + 1){
				dis[x*m+y] = dis[u] + 1;
				if( !inq[x*m+y] ){
					q.push(x*m+y);
					inq[x*m+y]=1;
				}
			}
		}
	}
	//bugn(dis,n*m);
	return dis[ n*m -1 ];
}
int32_t main(){
	IOS
	cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			cnt += s[i][j] =='.';
		}
	}
	bug2(cnt,spfa(0));
	int ans = cnt - spfa(0) -1;
	cout << (ans < 0 ? -1 : ans );
	
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
