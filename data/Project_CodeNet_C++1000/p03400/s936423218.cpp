#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  int n; cin >> n;
  int d,x; cin >> d >> x;
  vector<int> a(n) ;
  for(int i = 0;i < n; i++) cin >> a[i];
 
  // compute 
  vector<int> c(n) ;
  int sum = 0;
  int ans = 0;
  for(int i = 0; i < n; i++){
    c[i]= ((d - 1) / a[i]) + 1;
    sum += c[i];
  }

  ans = sum + x;
  
  // output  
  cout << ans << endl;
  
}