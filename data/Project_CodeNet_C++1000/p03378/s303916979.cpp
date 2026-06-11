#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, m, x;
  cin >> n >> m >> x;
  int a[n+1]={}, ia[n+1]={};
  for(int i=0; i<m; i++){
    int c; cin >> c;
    a[c] = 1;
  }
  int tmp=0, itmp=0;
  for(int i=0; i<x; i++){
    if(a[i]) tmp++;
  }
  for(int i=x+1; i<=n; i++){
    if(a[i]) itmp++;
  }
  int ans = min(tmp, itmp);
  cout << ans << endl;
  return 0;
}
