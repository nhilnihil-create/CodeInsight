#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
  // input
  int n,m,x;cin >> n >> m >> x;
  vector<int> a(m) ;
  vector<int> c(n) ;
  for(int i = 0;i < m; i++) cin >> a[i];
 
  // compute
  int sum = 0;
  int ans = 0;

  for(int i =0; i < m; i++){
    c[a[i]] = 1;
     }

  for(int i = 0; i < x; i++){
    sum += c[i];
     }

  ans = min(sum,m -sum);
 
  // output  
  cout << ans << endl;
  
}