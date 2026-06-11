//高速化なしver
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)();
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
typedef priority_queue<string> priquestring;
typedef priority_queue<int> priqueint;
typedef priority_queue<ll> priquell;
typedef priority_queue<char> priquechar;
typedef priority_queue<string,vector<string>,greater<string>> rpriquestring;
typedef priority_queue<int,vector<int>,greater<int>> rpriqueint;
typedef priority_queue<ll,vector<ll>,greater<ll>> rpriquell;
typedef priority_queue<char,vector<char>,greater<char>> rpriquechar;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

const ll big=1000000007;
int exp(int x,int y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x)%big;
    int t=exp(x,y/2);
    return (t*t)%big;
}
void chmin(ll a,ll b){
    if(a>b)a=b;
    return;
}

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};


int main(){
    int h,w;cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    queue<pair<int,int>> q;
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        if(a[i][j]=='#')q.push(pair<int,int>(i,j));
    }
    
    int cnt=-1;
    while(!q.empty()){
        int n=q.size();
        rep(i,n){
            pair<int,int> now=q.front();q.pop();
            rep(j,4){
                int nx=now.first+dx[j];int ny=now.second+dy[j];
                if(nx<0||ny<0||nx>=h||ny>=w)continue;
                if(a[nx][ny]=='#')continue;
                q.push(pair<int,int>(nx,ny));a[nx][ny]='#';
            }
        }
        cnt++;
    }
    cout << cnt << endl;
}