#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  int a,b;
  cin >> a >> b;
  ll ans=0;
  rep(i,0,2){
    if(a>b) {
      ans+=a;
      a--;
    }
  else{
      ans+=b;
      b--;
    }
  }
  cout << ans << endl;
  
  return 0;
}