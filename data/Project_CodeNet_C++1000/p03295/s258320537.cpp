#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;;

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  vector<int> r(n,INF);
  for(int i=0; i<m; i++) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    r[a] = min(r[a], b);
  }
  int x = INF, ans = 0;
  for(int i=0; i<n; i++){
    if (x == i) x = INF, ans++;
    x = min(x, r[i]);
  }

  cout<<ans<<endl;
  return 0;
}




















