#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
const double PI = acos(-1.0);
const long mod = 1000000007;
const long INF = 1e9 + 1;

int main() { 
  int d,g;
  cin >> d >> g;
  int p[d],c[d];
  for(int i = 0; i < d; i++)
    cin >> p[i] >> c[i];

  int mi = INF;
  for(int bit = 0; bit < (1 << d); bit++) {
    int cnt = 0,sum = 0, ma = 0;
    for(int i = 0; i < d; i++) {
      if(bit & (1 << i)) {
        sum += 100*(i+1)*p[i] + c[i];
        cnt += p[i];
      }
      else ma = max(ma, i); //選ばれないもののうちの最大
    }
    if(sum >= g) mi = min(mi, cnt);
    else {
      for(int i = 1; i < p[ma]; i++) {
        sum += 100*(ma+1);
        cnt++;
        if(sum >= g) {
          mi = min(mi,cnt);
          break;
        }
      }
    }
  }
  
  cout << mi << endl;
}