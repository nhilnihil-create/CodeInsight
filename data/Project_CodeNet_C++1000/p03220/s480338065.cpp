#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,t,a;
  cin >> n >> t >> a;
  t *= 1000;
  a *= 1000;
  int h[n];
  for(int i = 0; i < n; ++i){
    cin >> h[i];
  }
  
  int c = 100000000;
  int res = 0;
  
  for(int i = 0; i < n; ++i){
    int temp = t - 6 * h[i] - a;
    //cout << temp << " " << c << endl;
    if(abs(temp) < c){
      res = i;
      c = abs(temp);
    }
  }
  
  ++res;
  cout << res << endl;
}