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

int dist[10];

ll INF=1e5+2;

void bfs(vector<pi> edges[]){
	dist[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto w : edges[x] )
			if(dist[w.F] > dist[x]+w.S){
				dist[w.F]=dist[x]+w.S;
				//error(dist[w.F],w.F);
				q.push(w.F);
			}
	}
}

int main(){
	startTime=clock();
	int h,w;
	int c[10][10];
	cin >> h >> w;
	std::vector<pi> edges[10];
	FOR(i,10)
		FOR(j,10){
			cin >> c[j][i];
			edges[j].eb(MP(i,c[j][i]));
		}
	int a[h][w];
	int cost=0;
	FOR(i,10) dist[i]=INF;
	
	bfs(edges);
	FOR(i,h)
		FOR(j,w){
			cin >> a[i][j];
			if(a[i][j]!=1){
				cost+=dist[a[i][j]];
			}
		}
	cout << cost;


	return 0;
}