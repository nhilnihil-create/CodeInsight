#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;

  vector<int> c( N );
  vector<int> t( N );

  rep( i, 0, N ) {
    cin >> c.at( i );
    cin >> t.at( i );
  }

  int Ans = 1001;

  rep( i, 0, N ) {
    if ( t.at( i ) <= T ) {
      if ( c.at( i ) < Ans ) Ans = c.at( i );
    }
  }

  if ( Ans != 1001 ) {
    cout << Ans << endl;
  } else {
    cout << "TLE" << endl;
  }
}
