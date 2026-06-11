#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  double x, a = 0;
  string u;
  REP(i,n) {
    cin >> x >> u;
    if (u == "JPY") a += x;
    else a += x * 380000;
  }
  
  cout << a << endl;

}
