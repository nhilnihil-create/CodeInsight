#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int H, W; cin >> H >> W;
  int c[10][10];
  rep(i,10)rep(j,10) cin >> c[i][j];
  int A;
  map<int,int> d;
  rep(i,H) rep(j,W) {
    cin >> A;
    d[A]++;
  }

  queue<int> q;
  q.push(1);
  vector<int> dist(10,100000000);
  dist[1] = 0;
  while (!q.empty()){
    int a = q.front(); q.pop();
    rep(i,10){
      if (c[i][a]+dist[a]<dist[i]) {
        dist[i] = c[i][a] + dist[a];
        q.push(i);
      }
    }
  }
  ll ans = 0;
  for (auto p : d){
    if (p.first==-1) continue;

    ans += dist[p.first]*p.second;
  }
  cout << ans << endl;
  

  // cout << fixed << setprecision(10);
  
  return 0;
}
