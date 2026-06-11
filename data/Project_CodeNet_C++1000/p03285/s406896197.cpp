#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;

  bool flag = false;
  rep(x,100)
    rep(y,100)
    if(4*x+7*y==n) flag = true;

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
