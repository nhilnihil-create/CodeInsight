#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int A, B, K; cin >> A >> B >> K;

  vector<int> Ans;

  rep( i, 1, min( A, B )+1 ) {
    if ( A%i == 0 && B%i == 0 ) Ans.push_back(i);
  }

  cout << Ans.at( Ans.size()-K ) << endl;
}
