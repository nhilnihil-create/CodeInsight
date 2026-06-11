#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 
const vi ny={0,1,0,-1};
const vi nx={1,0,-1,0};

signed main(){
	int n,m; cin>>n>>m;
	vector<vector<char>> vec(n,vector<char>(m));
	int cnt=0;
	rep(i,0,n){
		rep(j,0,m){
			char c; cin>>c;
			if(c=='#') cnt++;
			vec[i][j]=c;
		}
	}
	queue<pi> q;
	q.push(pi(0,0));
	vvi bfs(n,vi(m));
	vector<vector<bool>> seen(n,vector<bool>(m));
	seen[0][0]=true;
	bfs[0][0]=1;
	while(!q.empty()){
		pi p=q.front(); q.pop();
		int a=p.first;
		int b=p.second;
		rep(i,0,4){
			int y=a+ny[i];
			int x=b+nx[i];
			if(y<0 || y>=n) continue;
			if(x<0 || x>=m) continue;
			if(vec[y][x]=='#') continue;
			if(seen[y][x]) continue;
			seen[y][x]=true;
			bfs[y][x]=bfs[a][b]+1;
			q.push(pi(y,x));
		}
	}
	if(!seen[n-1][m-1]){
		cout<<-1;
		return 0;
	}
	int ans=(n*m)-cnt-bfs[n-1][m-1];
	cout<<ans;
	
	return 0;
}