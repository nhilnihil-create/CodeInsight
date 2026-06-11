#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  
  int h[n];
  for(int i = 0; i < n; ++i){
    cin >> h[i];
  }
  sort(h,h+n);
  
  long long int res = 10000000000;
  for(int i = 0; i < n-k+1; ++i){
    long long int c = h[i+k-1] - h[i];
    res = min({res, c});
  }
  
  cout << res << endl;
}