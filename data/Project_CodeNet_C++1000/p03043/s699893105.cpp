#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  double n,k;
  cin >> n >> k;
  double i = 1;
  double ans = 0;
  while(i <= n){
	if(i >= k){
	  ans += 1;
    }
    else{
      double b = 1;
      double a = i;
      while(a < k){
        a *= 2;
        b = b / 2;
      }
      ans += b;
    }
    i++;
  }
  
  ans /= n;
  cout << std::fixed << std::setprecision(12) << ans << endl;
      
      
}
