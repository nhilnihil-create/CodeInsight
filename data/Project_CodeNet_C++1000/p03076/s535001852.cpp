#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int A, B, C, D, E;
int A0, B0, C0, D0, E0;

int main(){
  cin >> A >> B >> C >> D >> E;
  int X[5] = {A, B, C, D, E};
  int ANS = 200*5;
  do{
    int ans = 0;
    rep(i, 4){
      if (X[i] % 10 != 0){
        ans += X[i] + (10 - (X[i] % 10));
      }
      else ans += X[i];
    }
    ans += X[4];
    ANS = min(ANS, ans);
  }
  while (next_permutation(X, X+5));

  cout << ANS << endl;
}
