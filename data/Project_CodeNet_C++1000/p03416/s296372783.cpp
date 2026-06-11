#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)
#define rep2(i, s, n) for (int i=s; i<n; i++)

int main() {
  int a,b;
  cin >> a >> b;
  int cnt = 0;
  rep2(i, a, b+1) {
    string wk = to_string(i);
    if (wk[0]==wk[4] && wk[1]==wk[3]) {
      cnt++;
    }
  }
  cout << cnt << endl;
}