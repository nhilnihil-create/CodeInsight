#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n, d, x;
  cin >> n >> d >> x;
  
  int a;
  REP(i,n) {
    cin >> a;
    x += (d - 1) / a;
  }
  
  cout << x + n << endl;
  
}