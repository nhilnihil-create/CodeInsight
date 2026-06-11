#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int ans = 0;
  while(1){
    bool pl = false;
    rep(i, n){
      if (h[i] != 0){
        h[i]--;
        if (!pl){
          ans++;
          pl = true;
        }
      }
      else{
        pl = false;
      }
    }
    bool flag = true;
    rep(i, n){
      if (h[i] != 0) flag = false;
    }
    if (flag) break;
  }
  cout << ans << endl;
  
  return 0;
}