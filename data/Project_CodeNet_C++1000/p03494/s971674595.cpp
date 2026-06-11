#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, flg=0, ans=0;
  cin >> n;
  int A[n];

  rep(i, n)
  {
    cin >> A[i];
  }
  while(true)
  {
    rep(i, n)
    {
      if(A[i] % 2 != 0)
      {
        flg = 1;
        break;
      }
      else
      {
        A[i] /= 2;
      }
    }
    if(flg)
      break;
    ans++;
  }
  

  cout << ans << endl;

}
