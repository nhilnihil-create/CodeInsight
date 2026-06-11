#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,m,x;
  cin >> n >> m >> x;
  
  int a[m];
  rep(i,m) cin >> a[i];
  
  int right = 0;
  for(int i = x; i <= n; i++){
    for(int j = 0; j < m; j++){
      if(i == a[j]){
      right++;
      }
    }
  }
  
  int left = 0;
  for(int i = x; i >= 0; i--){
    for(int j = 0; j < m; j++){
      if(i == a[j]){
        left++;
      }
    }
  }
  
  cout << min(right,left) << endl;
}