#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  
  if(n >= 13){
    cout << m << endl;
    return 0;
  }
  else if(n < 13 && n >= 6){
    cout << m/2 << endl;
    return 0;
  }
  else{
    cout << 0 << endl;
    return 0;
  }
}