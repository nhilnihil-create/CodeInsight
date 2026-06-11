#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  REP(i,n){
    int a;
    cin >> a;
    ans += a;
  }
  ans -= n;
  
  cout << ans << endl;
  
}
