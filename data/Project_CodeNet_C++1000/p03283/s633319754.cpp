#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> c(n+1, vector<int>(n+1, 0));
  vector<vector<int>> x(n+1, vector<int>(n+1, 0));
  for(int i=0; i<m; i++){
    int l, r;
    cin  >> l >> r;
    x[l][r]++;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      c[i][j] = c[i][j-1] + x[i][j];
    }
  }
  for(int i=0; i<q; i++){
    int l, r;
    cin >> l >> r;
    int sum = 0;
    for(int j=l; j<=r; j++){
      sum += c[j][r]-c[j][l-1];
    }
    cout << sum << endl;
  }
  return 0;
}
