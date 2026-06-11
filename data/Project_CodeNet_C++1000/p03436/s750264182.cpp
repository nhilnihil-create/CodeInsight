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
	int h,w,black=0;
	cin >> h >> w;
	char s[h][w];
	FOR(i,h)
		FOR(j,w){
			cin >> s[i][j];
			if(s[i][j]=='#') black++;
		}
	int visited[h][w];

	int distance[h][w];
	FOR(i,h)
		FOR(j,w){
			distance[i][j]=INF;
			visited[i][j]=false;
		}
	int sides[2]={-1,1};
	queue<pi> q;
	distance[0][0]=0;
	q.push(MP(0,0));
	while(!q.empty()){
		int x=q.front().F;
		int y=q.front().S;
		q.pop();
		for(auto r: sides){
			if(x+r <h && x+r>-1 && s[x+r][y]=='.' && distance[x+r][y]>distance[x][y]+1){
				visited[x+r][y]=true;
				distance[x+r][y]=distance[x][y]+1;
				q.push(MP(x+r,y));
			}
			if(y+r < w && y+r>-1 && s[x][y+r]=='.' && distance[x][y+r]>distance[x][y]+1){
				visited[x][y+r]=true;
				distance[x][y+r]=distance[x][y]+1;
				q.push(MP(x,y+r));
			}
		}
	}
	if(visited[h-1][w-1]) cout << h*w-(black+distance[h-1][w-1]+1);
	else cout << -1;

	return 0;
}