#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}
int INF=1e5;
int main(){
	startTime=clock();
	int h,w;
	cin >> h >> w;
	string s[h];
	int black=0;
	FOR(i,h){
			cin >> s[i];
	}
	int visited[h][w];
	FOR(i,h)
		FOR(j,w)
			if(s[i][j]=='#') black++;
	FOR(i,h) 
		FOR(j,w) 
			visited[i][j]=false;
	int distance[h][w];
	FOR(i,h) 
		FOR(j,w)
			 distance[i][j]=INF;

	vector<pair<int,int>> edges[h*w];
	int side[2]={-1,1};
	FOR(i,h){
		FOR(j,w){
			if(s[i][j]=='.'){
				for(auto r : side){
					if(i+r<h && i+r>=0 && s[i+r][j]=='.'){
						
						edges[(i+r)*w+j].PB(MP(i,j));
					}
					if(j+r<w && j+r>=0 && s[i][j+r]=='.'){
						edges[i*w+j+r].PB(MP(i,j));
					}
				}
			}
		}
	}
	
	queue<pi> q;
	q.push(MP(0,0));
	distance[0][0]=0;
	visited[0][0]=true;
	
	while(!q.empty()){
		int x=q.front().F;
		int y=q.front().S;
		q.pop();

		for(auto v : edges[x*w+y]){
			int a=v.F;
			int b=v.S;
			visited[a][b]=true;
			if(distance[a][b]> distance[x][y]+1) {
				distance[a][b]=distance[x][y]+1;
				q.push(v);
			}
		}
	}
	
	if(visited[h-1][w-1]==false)cout << -1 ;
	else cout << h*w-(black+distance[h-1][w-1]+1);

	return 0;
}