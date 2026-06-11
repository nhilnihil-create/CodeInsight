#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int sum = 0;
  
  sum += a[0] + a[n-1];
  REP(i,n-1){
    sum += abs(a[i] - a[i+1]);
  }
  
  int ans = sum/2;
  cout << ans << endl;           
              
}