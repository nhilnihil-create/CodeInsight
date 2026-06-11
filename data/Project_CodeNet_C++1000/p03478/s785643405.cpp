#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b; cin >> n >> a >> b;
  int count = 0;
  for(int i = 1; i <= n; i++) {
    if(i < 10) {
      if(a <= i && i <= b) {
        count += i;
      }
    }
    else if (i < 100) {
      if(a <= (i /10 + i %10) && (i /10 + i %10) <= b) {
        count += i;
      }
    }
    else if(i < 1000) {
      if(a <= (i /100 + i %100 /10 + i %10) && (i /100 + i %100 /10 + i %10) <= b) {
        count += i;
      }
    }
    else if(i < 10000) {
      if(a <= (i /1000 + i %1000 /100 + i %100 /10 + i %10) && (i /1000 + i %1000 /100 + i %100 /10 + i %10) <= b) {
        count += i;
      }
    }
    else {
      if(a = 1) {
        count += i;
      }
    }
  }
  cout << count << endl;
}