#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int k;

  cin >> k;

  int ans = 0;

  for (int i = 1; i <= k; i++){
    for (int j = 1; j <= k; j++){
      if(i%2 == 0 && j%2==1)
        ans++;
    }
  }

  cout << ans;
}
