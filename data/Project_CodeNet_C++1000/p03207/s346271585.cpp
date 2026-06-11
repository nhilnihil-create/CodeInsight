#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> p( N );
  rep( i, 0, N ) cin >> p.at(i);

  sort( p.begin(), p.end() );
  p.back() /= 2;

  int Ans = 0;
  rep( i, 0, N ) {Ans += p.at(i);}

  cout << Ans << endl;
}
