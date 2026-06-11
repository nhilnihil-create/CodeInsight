#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 2e9;

int main() {
  int a, b;
  cin >> a >> b;
  if(a%b==0) {
    cout << -1 << endl;
    return 0;
  }
  else {
    for(int i=1; i<10000000; i++) {
      if((a*i)%b!=0) {
        cout << a*i << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}