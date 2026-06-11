#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n; 
  cin >> n;
  int ma=-1, mi=1000000009;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    ma = max(ma, a);
    mi = min(mi, a);
  }
  int ans = ma - mi;
  cout << ans << endl;
  return 0;
}
