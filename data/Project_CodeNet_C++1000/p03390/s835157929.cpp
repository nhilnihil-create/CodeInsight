#include<bits/stdc++.h>
using namespace std;
using I = long long;
int main() {
  int Q;
  cin >> Q;
  for(auto i=0; i<Q; ++i) {
    I A, B;
    cin >> A >> B;
    if(A > B) swap(A, B);
    I S = A*B;
    I s = sqrt(S);
    if(1<s && s*s == S) --s;
    I r = 2 * s;
    I a = s;
    I b = S/a;
    if(a*b == S) --b;
    if(a == b) {
      r -= 2;
      if(A!=a&&B!=b) ++r;
    } else if(a == A) {
      r -= 2;
      if(b!=A&&a!=B) ++r;
    }
    if(A < s) {
      a = A;
      b = S/a;
      r -= 2;
      if(b!=A&&a!=B) ++r;
    }
    cout << r << endl;
  }
}
