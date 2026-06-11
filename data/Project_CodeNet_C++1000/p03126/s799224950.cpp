#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,m;
  cin >> n >> m;
  vector<int> v(m,0);
  rep(i,n){
    int k;
    cin >> k;
    rep(j,k){
      int a;
      cin >> a;
      v[a-1]++;
    }
  }
  int ans = 0;
  rep(i,m){
    if(v[i] == n)ans++;
  }
  cout << ans << endl;
}