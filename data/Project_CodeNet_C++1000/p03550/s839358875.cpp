#include <bits/stdc++.h>
using namespace std;

int n;
int a[2002];
int m[2][2002];

int main() {
  cin>>n>>a[0]>>a[1];
  for (int i=0; i<n; i++) cin>>a[i+2];

  for (int i=n+1; i>1; i--) {
    m[0][i] = abs(a[i-1] - a[n+1]);
    for (int j=n+1; j>i; j--) {
      m[0][i] = max(m[1][j], m[0][i]);
    }
    m[1][i] = abs(a[i-1] - a[n+1]);
    for (int j=n+1; j>i; j--) {
      m[1][i] = min(m[0][j], m[1][i]);
    }
  }
  cout<<m[0][2]<<endl;
}