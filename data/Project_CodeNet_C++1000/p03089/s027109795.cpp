#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int N;
  cin >> N;
  
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);
  
  vector<bool> fg(N, true);
  vector<int> ans;
  for( int i = 0; i < N; i++ ){
    int cnt = 0;
    int num = -1;
    for( int j = 0; j < N; j++ ){
      if( fg.at(j) ) cnt++;
      if( A.at(j) == cnt ) num = j;
    }
    if( num != -1 ){
      fg.at(num) = false;
      ans.push_back(A.at(num));
    }
  }
  
  for( int i = 0; i < N; i++ ){
    if( fg.at(i) ){
      cout << -1 << endl;
      return 0;
    }
  }
  
  reverse(ans.begin(), ans.end());
  for( int i = 0; i < N; i++ ) cout << ans.at(i) << endl;
       
  
}
