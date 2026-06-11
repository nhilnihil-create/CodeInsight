#include <bits/stdc++.h>
using namespace std;


string g[55];
int main() {
  int n, m;
  cin>>n>>m;
  for (int i=0; i<n; i++) cin>>g[i];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (g[i][j]=='#') {
        cout<<"#"; continue;
      }
      int res=0;
      for (int dx=-1; dx<=1; dx++) {
        for (int dy=-1; dy<=1; dy++) {
          if (dx==0 && dy==0) continue;
          int x=dx+i; int y=dy+j;
          if (x>=0 && x<n && y>=0 && y<m) {
            res += (g[x][y]=='#');
          }
        }
      }
      cout<<res;
    }
    cout<<endl;
  }
  return 0;
}
