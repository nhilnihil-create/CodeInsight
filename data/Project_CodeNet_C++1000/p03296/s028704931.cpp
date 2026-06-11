#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  
  vector<int> slime(N);
  for( int i = 0; i < N; i++ ) cin >> slime.at(i);
  
  int ans = 0;
  int count = 1;
  for( int i = 1; i < N; i++ ){
    if( slime.at(i-1) == slime.at(i) ){
      count++;
    }else{
      ans += count/2;
      count = 1;
    }
  }
  ans += count/2;
  cout << ans << endl;
      
}
