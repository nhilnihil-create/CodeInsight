#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a[5];
  int x, ans = 0, mini = 10, n = 0;
  rep(i,5) {
    cin >> x;
    if (x % 10 == 0){
      ans += x;
    }
    else {
      mini = min(mini, x % 10);
      a[n] = x;
      n++;
    }
  }
  int w = 0;
  rep(i,n){
    if(a[i] % 10 == mini && w == 0){
      ans += a[i];
      w++;
    }
    else{
      ans = ans + ((a[i] / 10) + 1) * 10;
    }
  }
    
  cout << ans << endl;
  return 0;
}