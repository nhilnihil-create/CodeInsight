#include <bits/stdc++.h>
using namespace std;

int n,m,q;

int main() {
  cin >> n >> m >> q;
  int L[n+1][n+1];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=n;j++) {
      L[i][j]=0;
    }
  }
  for (int i=0;i<m;i++) {
    int a,b;cin >> a >> b;
    L[a][b]+=1;
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      L[i][j]+=L[i-1][j]+L[i][j-1]-L[i-1][j-1];
    }
  }
  for (int i=0;i<q;i++) {
    int c,d;cin >> c >> d;
    cout << L[d][d]-L[c-1][d]-L[d][c-1]+L[c-1][c-1] << endl;
  }
}
      