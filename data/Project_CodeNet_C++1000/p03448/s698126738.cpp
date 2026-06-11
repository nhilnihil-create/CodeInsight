#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int Ans = 0;
  rep(i, 0, A+1) {
    rep(j, 0, B+1) {
      rep(k, 0, C+1) {
        if ((500*i + 100*j + 50*k) == X) Ans++;
      }
    }
  }

  cout << Ans << endl;
}
