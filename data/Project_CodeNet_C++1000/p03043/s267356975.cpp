#include<bits/stdc++.h>
#define rep(i,n) for (int i=1; i<=(n); i++)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  double P = 0;
  rep(i,n) {
    double p = 1 / double(n);
    if (i < k) {
      int m = i;
      while (m < k) {
        p *= 0.5;
        m *= 2;
      }
      P += p;
    }
    else P += p;
  }
  
  cout << fixed << setprecision(12) << P << endl;
}