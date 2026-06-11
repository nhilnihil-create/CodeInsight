#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int m, k;
  cin >> m >> k;
  if (k >= (1 << m)) cout << -1 << endl;
  else if (m == 1 && k == 1) cout << -1 << endl;
  else if (m == 1 && k == 0) cout << "0 0 1 1" << endl;
  else{
    int ans[1<<(m+1)];
    ans[0] = k;
    ans[1<<m] = k;
    int add = 0;
    for (int i=0; i<(1<<m)-1; i++){
      if (i==k) add = 1;
      ans[i+1] = i + add;
      ans[(1<<(m+1))-i-1] = i + add;
    }

    for (int i=0; i<(1<<(m+1)); i++){
      cout << ans[i];
      if (i != (1<<(m+1))-1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}