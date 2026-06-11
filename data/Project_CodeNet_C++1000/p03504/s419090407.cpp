#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n, c;
  cin >> n >> c;
  vector<vector<int>> pro(c, vector<int>(100005, 0));
  for(int i=0; i<n; i++){
    int s, t, u;
    cin >> s >> t >> u;
    u--;
    pro[u][s] += 1;
    pro[u][t] -= 1;
  }
  int pro_t[100005] = {};
  for(int i=0; i<100005; i++){
    for(int j=0; j<c; j++){
      if(pro[j][i]==1) pro_t[i-1] += pro[j][i];
      else pro_t[i] += pro[j][i];
    }
  }
  int ans = 0;
  for(int i=0; i<100004; i++){
    pro_t[i+1] = pro_t[i] + pro_t[i+1];
    ans = max(ans, pro_t[i+1]);
  }
  cout << ans << endl;
  return 0;
}
