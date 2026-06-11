#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
 
  int a, b, k;
  cin >> a >> b >> k;
  
  vector<int> c(100);
  int j = 0;
  REP(i,100) {
    if (a % (i+1) == 0 && b % (i+1) == 0) {
      c[j] = i+1;
      j++;
    }
  }
  
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  
  cout << c[k-1] << endl;
 
}