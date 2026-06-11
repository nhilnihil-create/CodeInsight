#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int A;
  cin >> A;
  set<int> s;
  int a = A;
  int m = 1;
  while(!s.count(a)){
    s.insert(a);
    if(a %2 == 0) {
      a /= 2;
    }
    else {
      a = 3*a + 1;
    }
    m++;
  }
  cout << m << endl;
}