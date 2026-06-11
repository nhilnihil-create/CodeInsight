#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> t(n),x(n),y(n); rep(i,n) cin >> t[i] >> x[i] >> y[i];

  bool ok = true;
  if(n==1){
    int dx = x[0];
    int dy = y[0];
    int sum = dx+dy;
    if(sum!=t[0]) ok = false;
  }
  
  rep(i,n-1){
    int dx = abs(x[i+1]-x[i]);
    int dy = abs(y[i+1]-y[i]);
    int sum = dx+dy;
    int dif = t[i+1]-t[i];
    
    if(sum>dif) ok = false;
    else if((sum-dif)%2!=0) ok = false;
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
