#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int n,m,q;
  cin >> n >> m >> q;
  vector<pair<int,int>> v(m);
  int cnt[n+1][n+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      cnt[i][j]=0;
    }
  }
  for(auto &x:v){
    cin >> x.first >> x.second;
    cnt[x.first][x.second]++;
  }
  for(int i=0;i<=n;i++){
    for(int j=1;j<=n;j++){
      cnt[i][j]+=cnt[i][j-1];
    }
  }
  for(int i=0;i<=n;i++){
    for(int j=1;j<=n;j++){
      cnt[j][i]+=cnt[j-1][i];
    }
  }
  while(q--){
    int x,y;
    cin >> x >> y;
    cout << cnt[y][y]-cnt[y][x-1]-cnt[x-1][y]+cnt[x-1][x-1] << endl;
  }
}
