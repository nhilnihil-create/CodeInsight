#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }


  int count = 0;
  while(true) {
    for(int i = 0; i < n; i++) {
      if(a[i] % 2) {
        cout << count << endl;
        return 0;
      }
      a[i] = a[i] >> 1;
    }
    count++;
  }
  return 0;
}