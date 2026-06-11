#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const int INF = 1<<29;


int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<int>> table(10,vector<int>(10));
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin >> table[i][j];
    }
  }
  vector<vector<int>> a(h+1,vector<int>(w+1));
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> a[i][j];
    }
  }
  for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        if(table[i][j] > table[i][k] + table[k][j]){
          table[i][j] = table[i][k] + table[k][j];
        }
      }
    }
  }
  int ans = 0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(a[i][j] != -1){
        ans += table[a[i][j]][1];
      }
    }
  }
  cout << ans << endl;
}