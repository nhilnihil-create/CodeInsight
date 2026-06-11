#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  string S;
  cin >> S;

  int l = S.size();
  int Ans = 1000;

  for ( int i=0; i<=l-3; i++ ) {
    int num = ( S[i]-'0' )*100 + ( S[i+1]-'0' )*10 + ( S[i+2]-'0');
    Ans = min( Ans, abs( num-753 ) );
  }

  cout << Ans << endl;
}
