#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a1(n);
  vector<int> a2(n);
  REP(i,n){
    cin >> a1[i];
  }
  REP(i,n){
    cin >> a2[i];
  }
  
  int ans = 0;
  REP(i,n){
    int sum = 0;
    REP(j,i+1){
      sum += a1[j];
    }
    REP(j,n-i){
      sum += a2[n-j-1];
    }
    ans = max(ans,sum);
  }
  

  cout << ans << endl;
}
