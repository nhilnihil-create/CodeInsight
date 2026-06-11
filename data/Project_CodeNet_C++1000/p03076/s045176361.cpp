#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  vector<int> a(5);
  vector<int> b(5);
  int s,t  = 0,ans = 0;
  rep(i,5) { 
    cin >> a.at(i);
    b.at(i) = (a.at(i)+9)/10*10;
    ans += b.at(i);
    int d = b.at(i) - a.at(i);
    if(d  > t) {
      t = d;
      s = i;
    }
  }
  ans -= b.at(s) - a.at(s);
  cout << ans << endl;
}
  
