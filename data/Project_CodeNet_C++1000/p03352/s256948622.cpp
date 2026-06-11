#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define REP2(i, n) for (int i = 2; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int x;
  cin >> x;
  int mx = 0;
  REP(i,1000){
	REP2(j,1000){
      ll n1 = pow(i,j);
      if(n1 >= mx && n1 <= x){
        mx = n1;
      }
    }
  }
                                       
  cout << mx << endl;                                     
}