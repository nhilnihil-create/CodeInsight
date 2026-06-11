#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int d[] = {1,0,-1,0,1};

int main(){
  int h,w;
  cin>>h>>w;
  char C[1010][1010];
  for(int i=1; i<=h; i++){
    for (int j=1; j<=w; j++) cin >> C[i][j];
  }
  int V[1010][1010] = {0};

  queue<pii> Q;
  for(int i=1; i<=h; i++){
    for (int j=1; j<=w; j++){
      if (C[i][j] == '#'){
        V[i][j] = 1;
        Q.push(make_pair(i,j));
      }
    }
  }

  while(!Q.empty()){
    int tmp_h = Q.front().first;
    int tmp_w = Q.front().second;
    Q.pop();
    rep(i,4){
      if (V[tmp_h+d[i]][tmp_w+d[i+1]] == 0 && tmp_h+d[i] >= 1 && tmp_h+d[i] && tmp_h+d[i] <= h
        && tmp_w+d[i+1] >= 1 && tmp_w+d[i+1] <= w){
        V[tmp_h+d[i]][tmp_w+d[i+1]] = V[tmp_h][tmp_w] + 1;
        Q.push(make_pair(tmp_h+d[i], tmp_w+d[i+1]));
      }
    }
  }
  int ans = -1;
  for(int i=1; i<=h; i++){
    for (int j=1; j<=w; j++){
      ans = max(ans, V[i][j]);
    }
  }
  cout << ans - 1 << endl;
}
