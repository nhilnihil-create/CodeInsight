#include<bits/stdc++.h>
using namespace std;
using I = long long;
int main() {
  int Q;
  cin >> Q;
  for(auto i=0; i<Q; ++i) {
    I A, B;
    cin >> A >> B;
    I S = A*B;
    I low = 1, high = S;
    while(high-low > 1) {
      I a = (low + high) / 2;
      I b = S/a;
      if(a*b==S) --b;
      if(a<=b) low  = a;
      else     high = a;
    }
    I r = low * 2;
    I a, b;
    a = low;
    b = S/a;
    if(a*b==S) --b;
    if(a==b) {
      r -= 2;
      if(a!=A&&b!=B) ++r;
    } else if(a==A) {
      r-=2;
      if(b!=A&&a!=B) ++r;
    }
    if(A < low) {
      a = A;
      b = S/a;
      r-=2;
      if(b!=A&&a!=B) ++r;
    }
    b = B;
    a = S/b;
    if(b<low) {
      r-=2;
      if(b!=A&&a!=B) ++r;
    }
    cout << r << endl;
  }
}
