#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  vector<int> b(n), ans;
  rep(i, n) cin >> b[i];

  for(int j = 0; j < n; j++){
    for(int i = b.size() - 1; i >= 0; i--){
      if(b[i] == i + 1){
        ans.push_back(b[i]);
        b.erase(b.begin() + i);

        break;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  if(ans.size() != n) cout << -1 << endl;
  else rep(i, n) cout << ans[i] << endl;

  return 0;
}
