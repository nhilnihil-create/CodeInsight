#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, k;
  cin >> n >> k;
  int ans = 1;
  int cnt = 0;
  while(cnt < n){
    if(ans * 2 < ans + k){
      ans *= 2;
    }
    else{
      ans += k;
    }
    cnt++;
  }
  cout << ans << endl;

  return 0;
}
