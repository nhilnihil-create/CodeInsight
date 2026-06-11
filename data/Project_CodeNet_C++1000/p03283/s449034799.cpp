#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int main(){

  int n,m,q;
  cin >> n >> m >> q;

  int s[n+1][n+1],a[n+1][n+1];
  memset(s,0,sizeof(s));
  memset(a,0,sizeof(a));

  for(int i=0;i<m;i++){
    int l,r;
    cin >> l >> r;
    a[l][r]++;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+a[i+1][j+1];
    }
  }

  for(int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    cout << s[n][r]-s[l-1][r] << endl;;
  }

}