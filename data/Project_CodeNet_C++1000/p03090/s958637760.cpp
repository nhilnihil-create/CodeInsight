#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  bool edge[n+1][n+1];
  int k;
  if (n % 2 == 0) {
    k = n + 1;
  } else {
    k = n;
  }
  for (int i=1; i<n+1; i++) {
    for (int j=1; j<n+1; j++) {
      if (i == j || i + j == k) {
        edge[i][j] = false;
      } else {
        edge[i][j] = true;
      }
    }
  }
  int m = 0;
  for (int i=1; i<n+1; i++) {
    for (int j=i+1; j<n+1; j++) {
      m += edge[i][j];
    }
  }
  cout<<m<<endl;
  for (int i=1; i<n+1; i++) {
    for (int j=i+1; j<n+1; j++) {
      if (edge[i][j]) {
        cout<<i<<" "<<j<<endl;
      }
    }
  }
}