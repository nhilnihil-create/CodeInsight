#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int a,b,k;
  cin >> a >> b >> k;
  int ans, t = 0;
  int n = min(a, b);
  for(n; n > 0; n--){
    if(a % (n) == 0 && b % (n) == 0) {
      t++;
      if (t == k){
        ans = n;
      }
    }
  }
  cout << ans << endl;
  return 0;
}