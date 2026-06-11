#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int h, w;
string s[1010];
vector<vector<int>> dist(1010,vector<int>(1010, inf));
int main(){
    cout << fixed << setprecision(10);
    cin >> h >> w;
    rep(i,h) cin >> s[i];
    ll ans = 0;
    vector<pair<int,int>> vii;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                dist[i][j] = 0;
                vii.push_back({i,j});
            }
        }
    }
    queue<pair<int,int>> que;
    for(auto u : vii) que.push({u.first, u.second});
    while(!que.empty()){
        int x = que.front().first, y = que.front().second;
        que.pop();
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        rep(i,4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w){
                if(dist[nx][ny] == inf){
                    dist[nx][ny] = dist[x][y] + 1;
                    ans = dist[x][y] + 1;
                    que.push({nx,ny});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}