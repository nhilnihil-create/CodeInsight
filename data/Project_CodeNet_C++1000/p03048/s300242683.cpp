#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
  int r,g,b,n; cin >>r >>g >>b >>n;
  int cnt = 0;
  int rn = n/r, gn = n/g;
  for(int i = 0; i<=rn; i++){
    for(int j = 0; j<=gn; j++){
      int x = n-r*i-g*j;
      if(x<0) continue;
      if(x%b==0) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}