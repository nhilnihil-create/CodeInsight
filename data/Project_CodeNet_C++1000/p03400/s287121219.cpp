#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n,d,x;
  cin >> n >> d >> x;
  int a[n];
  
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int sum = x;

  for(int i = 0; i < n; i++) {
    int count = 0;
    while(count*a[i]+1 <= d) {
      count++;
    }
    sum += count;
  }
  cout << sum << endl;
  return 0;
}