#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> odd(100010, 0), even(100010, 0);
  
  for (int i = 0; i < n; i++) {
    int v;
    if (i % 2) {
      cin >> v;
      odd[v]++;
    } else {
      cin >> v;
      even[v]++;
    }
  }
  
  int oddmax = 0, oddmax_num = 0, 
  evenmax = 0, evenmax_num = 0, oddmax2nd = 0, evenmax2nd = 0;
  
  for (int i = 1; i <= 100000; i++) {

    if (oddmax <= odd[i]) {
      oddmax2nd = oddmax;
      oddmax = odd[i];
      oddmax_num = i;
    } else if (oddmax2nd <= odd[i]) {
      oddmax2nd = odd[i];
    }
    
    if (evenmax <= even[i]) {
      evenmax2nd = evenmax;
      evenmax = even[i];
      evenmax_num = i;
    } else if (evenmax2nd <= even[i]) {
      evenmax2nd = even[i];
    }
  }
  

  if (oddmax_num == evenmax_num) {
    cout << n - max(oddmax + evenmax2nd, evenmax + oddmax2nd) << endl;
  } else {
    cout << n - oddmax - evenmax << endl;
  }
  
}