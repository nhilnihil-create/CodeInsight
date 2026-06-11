//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int n;
vector<vector<int> > to;
vector<int> point;
priority_queue<int> q;
void dfs(int v,int p=-1){
  point[v]=q.top();
  q.pop();
  rep(i,to[v].size()){
    int nv=to[v][i];
    if(nv==p) continue;
    dfs(nv,v);
  }
}
int main(){
  cin >> n;
  to.resize(n,vector<int>(0));
  point.resize(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  ll score=0;
  rep(i,n){
    int c; cin >> c;
    q.push(c);
    score+=c;
  }
  score-=q.top();
  cout << score << endl;
  dfs(0);
  rep(i,n){
    cout << point[i] << " ";
  }cout << endl;
}