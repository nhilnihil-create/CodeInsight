#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  // input
    long n,m;cin >> n >> m;
    long ans;
    ans = 0;
  

  // compute 
    ans = (1900 * m + 100 * (n - m)) ;
    for(int i = 0;i < m; i++) {
      ans *= 2;
    }

  // output  
    cout << ans << endl;
}