#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define out(ans) cout << ans << endl;
const long long mod = 1e9 + 7;

int main(){

  ll x,y;cin>>x>>y;
  if(x%y==0){
    out(-1);
  }else{
    out(x);
  }

  return 0;
}
