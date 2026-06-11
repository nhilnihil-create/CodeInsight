#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int A,B,C; cin>>A>>B>>C;
  int alph=max(max(A,B),C);
  if(alph == A) cout << alph*10+B+C << endl;
  else if(alph == B) cout << alph*10+A+C << endl;
  else cout << alph*10+A+B << endl;
}
