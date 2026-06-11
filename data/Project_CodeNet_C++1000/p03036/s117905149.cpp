#include <bits/stdc++.h>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))
 
typedef long long ll;
 
using namespace std;
 
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int r,d,x; cin>>r>>d>>x;
  int res[10];
  
  rep(i,10) {
    if(i==0) {
      res[i] = r*x-d;
    } else {
      res[i] = r*res[i-1]-d;
    }
  }
  
  rep(i,10) {
    cout<<res[i]<<endl;
  }
  
  return 0;
}