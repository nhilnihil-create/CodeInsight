#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

signed main() {
  int N;
  cin >> N;
  vector<bool> IsPrime(60000, true);
  IsPrime.at(0) = false;
  IsPrime.at(1) = false;
  for( int i = 2; i <= 55555; i++ ){
    if( IsPrime.at(i) == true ){
      for( int j = 2; i*j <= 55555; j++ ) IsPrime.at(i*j) = false;
    }
  }
  
  vector<int> P;
  for( int i = 2; i <= 55555; i++ ){
    if( IsPrime.at(i) == true ) P.push_back(i);
  }
  
  int cnt = 0;
  for( int i = 0; i < P.size(); i++ ){
    if( P.at(i)%5 == 1 ){
      cout << P.at(i) << " ";
      cnt++;
    }
    if( cnt == N ){
      cout << endl;
      return 0;
    }
  }
  
  
}