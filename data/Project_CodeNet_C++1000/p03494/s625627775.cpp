#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int a;
  int count = 0;
  int min = 100;
  for(int i=0; i<n; i++) {
    cin >> a;
    while(1) {
      if(a%2==0) {
        count++;
        a /= 2;
      }
      else if(count<min) {
        min = count;
        break;
      }
      else break;
    }
    count = 0;
  }
  cout << min << endl;
  return 0;
}