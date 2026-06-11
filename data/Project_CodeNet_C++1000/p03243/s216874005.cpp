#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;

  int Ans = 0;
  rep( i, N, 1000 ) {
    if ( i%111 == 0 ) {
      Ans = i;
      break;
    }
  }

  cout << Ans << endl;
}
