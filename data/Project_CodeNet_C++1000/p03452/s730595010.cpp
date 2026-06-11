#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;


int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pp>> e(n+1,vector<pp>(0));
  vector<int> b(n+1,-inf);
  rep(i,m){
    int f,g,h;
    cin >> f >> g >> h;
    e[f].push_back(mk(g,h));
    e[g].push_back(mk(f,-h));
  } 
  for(int k=1;k<=n;k++){
  if (b[k]!=-inf) continue;
  queue<int> q;
  q.push(k);
  b[k]=0;
  while(!q.empty()){
    int f=q.front();
    q.pop();
    rep(i,e[f].size()){
      int u=e[f][i].first,y=e[f][i].second;
      if (b[u]==-inf){
        b[u]=b[f]+y;
        q.push(u);
      }
      else{
        if (b[u]!=b[f]+y){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  }
  cout << "Yes" << endl;
}
