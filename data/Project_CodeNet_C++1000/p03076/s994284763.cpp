#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int KiriageTime(int x) {
  return (x+9) /10 *10;
}

int sabun(int x) {
  return KiriageTime(x) -x;
}

int main() {
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;

  int KiriageTotal = KiriageTime(A) + KiriageTime(B) + KiriageTime(C) + KiriageTime(D) + KiriageTime(E);
  cout << KiriageTotal - max( {sabun(A), sabun(B), sabun(C), sabun(D), sabun(E)} ) << endl;
}
