#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<int> m(n);
  rep(i, n) cin >> m[i];
  sort(m.begin(), m.end(), greater<int>());
  int buf = 101;
  int ans = 0;
  rep(i, n){
    if(m[i] < buf){
      ans += 1;
      buf = m[i];
    }
  }
  cout << ans << endl;
}
