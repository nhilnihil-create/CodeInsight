#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  int s; cin >> s;
 
  // compute
  vector<int> a(10000000);
  vector<int> c(10000000);
  int ans = 0;
 
  a[1] = s;
  c[s] = 1;
  
  for(int i = 2;i < 10000000; i++){
    if(a[i-1] % 2 == 0){
        a[i] = a[i-1] / 2 ;
        if(c[a[i]] == 1){
            ans = i;
            break;
        }else{
            c[a[i]] = 1;
        }
    }else{
        a[i] = (a[i-1] * 3) + 1;
        if(c[a[i]] == 1){
            ans = i;
            break;
        }else{
            c[a[i]] = 1;
        }
    }
  }
  
  // output  
  cout << ans << endl;
  
}