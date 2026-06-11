#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,T;
  cin >> n >> T;
  
  int c[n],t[n];
  rep(i,n) cin >> c[i] >> t[i];
  
  int ans = 1001;
  rep(i,n){
    if(t[i] <= T && c[i] < ans){
      ans = c[i];
    }
  }
  
  if(ans == 1001){
    cout << "TLE" << endl;
  }else{
    cout << ans << endl;
  }
      
}