#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n, x;
  cin >> n >> x;
  
  int m, sum = 0, l = 1001;
  REP(i,n) {
    cin >> m;
    sum += m;
    l = min(l,m);
  }
  
  n += (x - sum) / l;
  
  cout << n << endl;
  
}