#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int ans = 700;
  rep(i,3){
    char c;
    cin >> c;
    if(c=='o'){
      ans += 100;
    }
  }
  cout << ans << endl;
  
}      
  