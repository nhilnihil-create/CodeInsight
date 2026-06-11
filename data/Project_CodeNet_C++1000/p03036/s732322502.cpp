#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;



int main() {
  int r,d,x;
  cin >> r >> d >> x;
  
  
  REP(i,10){
    x = ((r*x) - d);
    cout << x << endl;
  }

  
}