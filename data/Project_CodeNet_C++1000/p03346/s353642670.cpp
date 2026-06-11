#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);

  vector<int> X(N+1);
  for( int i = 0; i < N; i++ ){
    X.at(A[i]) = X.at(A[i]-1)+1;
  }

  int hiku = 0;
  for( int i = 1; i <= N; i++ ) hiku = max(hiku, X[i]);
  cout << N-hiku << endl;

}
