#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, h;
  cin >> n >> h;
  int a = 0;
  vector<int> b(n);
  rep(i,n) {
    int x;
    cin >> x >> b[i];
    a = max(a,x);
  }
  sort(rng(b));
  reverse(rng(b));
  int i = 0;
  int cnt = 0;
  while(h>0) {
    if(a>=b[i]||i==n) {
      cnt += (h+a-1)/a;
      break;
    }
    else {
      h -= b[i];
      cnt++;
      i++;
    }
  }
  cout << cnt << endl;
  return 0;
}