#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
//using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

ll h,w;
char a[1010][1010];

int dist[1010][1010];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<P>start;

void bfs(){
    queue<P> que;
    rep(i,start.size()){
        que.push(start[i]);
        dist[start[i].first][start[i].second]=0;
    }
    while(!que.empty()){
        P p = que.front();que.pop();
        rep(dir,4){
            int nx = p.first + dx[dir];
            int ny = p.second + dy[dir];
            if(nx<0||ny<0||nx>=h||ny>=w)continue;
            if(dist[nx][ny]>=0)continue;
            que.push(P(nx,ny));
            dist[nx][ny]=dist[p.first][p.second]+1;
        }   
    }
    return;
}

int main(){
    cin >> h >> w;
    rep(i,h)rep(j,w){
        cin>>a[i][j];
        if(a[i][j]=='#')start.push_back(P(i,j));
    }
    rep(i,h)rep(j,w)dist[i][j]=-1;
    bfs();
    int ans = 0;
    rep(i,h)rep(j,w)chmax(ans,dist[i][j]);
    cout << ans << endl;

    return 0;
}
