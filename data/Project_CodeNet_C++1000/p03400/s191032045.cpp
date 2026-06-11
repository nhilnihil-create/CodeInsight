#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, D, X;
  cin >> N >> D >> X;
  int co = 0;
  int A;
  int AA;
  int sum = 0;
  rep(i, N) {
    cin >> A; 
    AA = A;
    while(true) {
      co++;
      if(co == 1) {
        AA = A + 1;
      }
      else {
        AA = AA + A;
      }
      if(AA > D) {
        break;
      }
    }
    sum += co;
    co = 0;
  }
  cout << sum + X << endl;
}