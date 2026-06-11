#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;


signed main(){
  
  string S;
  cin >> S;
  
  int ans = 0;
  int l = 0;
  int r = S.size()-1;
  while( l < r ){
    if( S.at(l) == S.at(r) ){
      l++;
      r--;
    }else if( S.at(l) == 'x' ){
      ans++;
      l++;
    }else if( S.at(r) == 'x' ){
      ans++;
      r--;
    }else{
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  
}
