#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;


int main() {
  int cnt = 0;
  rep(i,3){
    char a;
    cin >> a;
    if(a == 'o')cnt++;
  }
  int ans = 700 + 100 * cnt;
  cout << ans << endl;
}
