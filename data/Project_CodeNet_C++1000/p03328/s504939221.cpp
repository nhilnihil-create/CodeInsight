#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int a,b,c,d = 0;
  cin >> a >> b;
  c = b-a;
  REP(i,c+1){
    d += i;
  }
  
  cout << d-b << endl;
}
