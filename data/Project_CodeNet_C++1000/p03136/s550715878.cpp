#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> L( N );
  rep( i, 0, N ) cin >> L.at(i);

  sort( L.begin(), L.end() );

  bool flag = false;
  int x = 0;
  rep( i, 0, N-1 ) {
    x += L.at(i);
  }
  if ( L.back() < x ) {
    flag = true;
  }

  cout << ( flag ? "Yes" : "No" ) << endl;
}
