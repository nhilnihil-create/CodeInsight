#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, c;
  cin >> n >> c;
  vector<vector<int>> d(c, vector<int>(c));
  for(int i=0; i<c; i++){
    for(int j=0; j<c; j++){
      cin >> d[i][j];
    }
  }
  vector<vector<int>> color(3, vector<int>(c, 0));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int a;
      cin >> a;
      a--;
      color[(i+j)%3][a]++;
    }
  }
  int ans = 1000000009;
  for(int i=0; i<c; i++){
    for(int j=0; j<c; j++){
      if(i==j) continue;
      for(int k=0; k<c; k++){
        if(i==k || j==k) continue;
        int tmp = 0;
        for(int m=0; m<c; m++){
          tmp += color[0][m]*d[m][i];
          tmp += color[1][m]*d[m][j];
          tmp += color[2][m]*d[m][k];
        }
        ans = min(tmp, ans);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
