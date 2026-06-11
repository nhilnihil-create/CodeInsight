#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int a, b;
  cin >> a >> b;
  
  int ans = 0, c = 0;  
  REP(i,1000) {
    c += i;
    if (c - a == c + i + 1 - b) cout << c - a;
  }

}
