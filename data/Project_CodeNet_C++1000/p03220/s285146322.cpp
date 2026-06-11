#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  double n,t,a,h[2000],x[2000];
  cin >> n >> t >> a; 
  for(int i = 0; i < n; i++) {
    cin >> h[i];
    x[i] = 1000*t - h[i] * 6;
  }

  int mi = 1000000000, num;
  for(int i = 0; i < n; i++) {
    if(mi > abs(x[i]-1000*a)) {
      mi = abs(x[i]-1000*a);
      num = i;
    }
  }
  cout << num+1 << endl;
}
