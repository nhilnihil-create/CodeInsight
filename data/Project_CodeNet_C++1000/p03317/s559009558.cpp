#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  int m;

  REP(i,n){
    cin >> a[i];
    if(a[i] == 1) m = i;
  }
  
  m++;
  while(1){
    if((n - m) % (k-1)== 0){
      break;
    }
    m++;
  }
  int ans = 0;

  int i = 0;
  int p1 = m;
  while(1){
    if(p1 <= 1) break;
    p1 -= k-1;
    i++;
  }
  ans += i;
  i = 0;
  p1 = m;
  while(1){
    if(p1 >= n) break;
    p1 += k-1;
    i++;
  }
  ans += i;  
  
  cout << ans << endl;
  
}
