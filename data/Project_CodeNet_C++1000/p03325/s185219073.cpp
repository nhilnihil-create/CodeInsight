#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,ans = 0;
  cin >> n;
  REP(i,n){
    int a;
    cin >> a;
    while(1){
      if(a % 2 != 0) break;
      a /= 2;
      ans++;
    }
  }
  
  cout << ans << endl;
}
