#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<vector<int>>a(3,vector<int>(n+1,0));
  vector<vector<int>>b(3,vector<int>(n+1,0));
  for(int i=0;i<2;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  b[0][0]=a[0][0];
  for(int j=1;j<n+1;j++){
    b[0][j]=a[0][j]+b[0][j-1];
  }
  b[1][0]=a[0][0]+a[1][0];
  for(int j=1;j<n+1;j++){
    b[1][j]=a[1][j]+max(b[1][j-1],b[0][j]);
  }
  cout<<b[1][n-1]<<endl;
  return 0;
}
