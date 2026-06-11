#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N; cin >> N;

  vector<int> V(N);
  rep( i, 0, N ) cin >> V.at(i);

  vector<int> C(N);
  rep( i, 0, N ) cin >> C.at(i);

  int Ans = 0;
  rep( i, 0, N ) {
    int temp = V.at(i) - C.at(i);
    if ( temp > 0 ) Ans += temp;
  }

  cout << Ans << endl;
}
