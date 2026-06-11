#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);
  vector<int> B(N);
  for( int i = 0; i < N; i++ ) cin >> B.at(i);
  
  int cnt = 0;
  for( int i = 0; i < N; i++ ){
    if( A.at(i) > B.at(i) ) cnt += A.at(i)-B.at(i);
    else if( A.at(i) < B.at(i) ) cnt -= (B.at(i)-A.at(i))/2;
  }
  
  if( cnt <= 0 ) cout << "Yes" << endl;
  else cout << "No" << endl;
}