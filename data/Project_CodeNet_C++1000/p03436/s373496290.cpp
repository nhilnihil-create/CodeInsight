#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(a) int((a).size())
#define endl '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int INF = 1e9+10;
const int maxn = 60;
	
int h,w,white=0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char g[maxn][maxn];
int dist[maxn][maxn];

bool ok(int x,int y){
	return x>=1 && x<=h && y>=1 && y<=w && g[x][y]=='.';
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#endif
	cin>>h>>w;
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j){
			cin>>g[i][j];
			if(g[i][j]=='.')
				white++;
		}
	}
	for(int i=0;i<maxn;++i){
		for(int j=0;j<maxn;++j){
			dist[i][j]=INF;
		}
	}
	queue<ii> q;
	q.push(ii(1,1));
	dist[1][1]=1;
	while(!q.empty()){
		int x=q.front().ff,y=q.front().ss;
		q.pop();
		for(int i=0;i<4;++i){
			if(ok(x+dx[i],y+dy[i]) && dist[x][y]+1 < dist[x+dx[i]][y+dy[i]]){
				dist[x+dx[i]][y+dy[i]]=dist[x][y]+1;
				q.push(ii(x+dx[i],y+dy[i]));
			}
		}
	}
	if(dist[h][w]==INF)
		cout<<-1<<endl;
	else
		cout<<white-dist[h][w]<<endl;
	return 0;
}