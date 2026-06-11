#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, m;
  cin >> n >> m;
  int a[n+1]={};
  for(int i=0; i<m; i++){
    int l, r;
    cin >> l >> r;
    l--;
    a[l] += 1;
    a[r] -= 1;
  }
  int ans = 0;
  if(a[0]==m) ans++;
  for(int i=1; i<n; i++){
    a[i] += a[i-1];
    if(a[i]==m) ans++;
  }
  cout << ans << endl;
  return 0;
}
