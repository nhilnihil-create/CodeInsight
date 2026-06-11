#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  vector<int> h(n);
  REP(i,n) {
    cin >> h[i];
  }
  
  int count = 0;
  REP(i,n) { 
    if (h[i] > 0) {
      REP(j,n-i) {
        if (h[i+j] > 0) h[i+j]--;
        else break;
      }
      count++;
      if (h[i] > 0) i--;
    }
  }
  
  cout << count << endl;
}