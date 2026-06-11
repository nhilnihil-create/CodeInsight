#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;



int main(){
  int n;
  cin >> n;

  
  int ans = 0;
  int d[100001] = {0};
  rep(i,n) {
    int a;
    cin >> a;
    if(a > 100000) {
      ans++;
      continue;
    }
    d[a]++;
  }

  rep(i,100001){
    if(d[i] > i) ans += d[i]-i;
    if(i > d[i]) ans += d[i];
  }
  cout << ans << endl;
}
