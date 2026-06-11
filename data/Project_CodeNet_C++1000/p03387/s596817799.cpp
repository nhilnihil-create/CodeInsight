#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  
  vector<int> a(3);
  
  REP(i,3) cin >> a[i];
  
  sort(a.begin(), a.end());
  
  int ans = 0;
  if((a[2] - a[1]) % 2 == 0 &&(a[2] - a[0]) % 2 == 0){
    ans += (a[2] - a[1]) / 2 + (a[2] - a[0]) / 2;
  }
  else if((a[2] - a[1]) % 2 == 1 &&(a[2] - a[0]) % 2 == 1){
    int n = (a[2] - a[1]) / 2;
    int m = (a[2] - a[0]) / 2;
    ans += n + m + 1;
  }
  else{
    int n = (a[2] - a[1]) / 2;
    int m = (a[2] - a[0]) / 2;
    ans += n + m + 2;
  }
          
          
  cout << ans << endl;
  
}