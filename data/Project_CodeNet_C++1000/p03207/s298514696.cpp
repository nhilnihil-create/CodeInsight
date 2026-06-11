#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  int a, sum = 0, m = 0;
  REP(i,n) {
    cin >> a;
    sum += a;
    m = max(m,a);
  }
  
  cout << sum - m / 2 << endl;
  
}     