#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  
  int x;
  int sum = 0;
  for(int i=1; i<=999; i++) {
    sum += i;
    if(sum > a) {
      x = sum + i+1;
      if(x > b) {
        if(sum-a == x-b) {
        cout << sum-a << endl;
        return 0;
        }
      }
    }
  }
}