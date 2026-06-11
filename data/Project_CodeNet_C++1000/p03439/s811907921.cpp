#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;

  string t[3] = {"Male", "Female", "Vacant"};
  vector<string> s(n);
  cout << 0 << endl;
  cin >> s[0];
  if(s[0] == t[2]){
    cout << 0 << endl;
    return 0;
  }

  int left = 0, right = n-1;
  while(right - left > 1){
    int mid = (left + right) / 2;
    cout << mid << endl;
    cin >> s[mid];
    if(s[mid] == t[2]) return 0;
    if((mid - left + 1) % 2 == 0){
      if(s[left] != s[mid]){
        left = mid;
      }else {
        right = mid;
      }
    }else {
      if(s[left] == s[mid]){
        left = mid;
      }else {
        right = mid;
      }
    }
  }
  cout << right << endl;

  return 0;
}
