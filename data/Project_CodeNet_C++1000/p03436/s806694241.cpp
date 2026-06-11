#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll gcd(ll a,ll b) {return  b ? gcd(b,a%b) : a;}
const long long INF = 1LL << 60;
const int mod = 1000000007;
const double PI = acos(-1.0);
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int h,w;
bool seen[51][51];
char fi[51][51];
void dfs(int x,int y){
     seen[x][y]=true;
     
          rep(i,4){
               int nx = x+dx[i];
               int ny = y+dy[i];
               if(nx<0||nx>=h||ny<0||ny>=w)continue;
               if(fi[nx][ny]=='#')continue;
               if(seen[nx][ny])continue;
               dfs(nx,ny);
          }
}

int main () {
     cin >> h >> w;
     rep(i,h){
          rep(j,w){
               cin >> fi[i][j];
          }
     }
     memset(seen,false,sizeof(seen));
     dfs(0,0);
     if(!seen[h-1][w-1]) {
          cout << -1 <<endl;
          return 0;
     }
     using pint = pair<int,int>;
     queue<pint>que;
     que.push({0,0});
     int dist[51][51];
     memset(dist,-1,sizeof(dist));
     dist[0][0]=0;
     while(!que.empty()){
          int a = que.front().first;
          int b = que.front().second;
          if(a==h-1&&b==w-1) break;
          que.pop();
          rep(i,4){
               int nx = a+dx[i];
               int ny = b+dy[i];
               if(nx<0||nx>=h||ny<0||ny>=w)continue;
               if(fi[nx][ny]=='#')continue;
               if(dist[nx][ny]!=-1)continue;
               dist[nx][ny]=dist[a][b]+1;
               que.push({nx,ny});
          }
     }
     int kei = dist[h-1][w-1] +1;
     int black = 0;
     rep(i,h){
          rep(j,w){
               if(fi[i][j]=='#') black++;
          }
     }
     int ans = w*h-kei-black;
     cout << ans <<endl;
}