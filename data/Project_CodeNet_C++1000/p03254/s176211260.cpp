#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  long n,x,a[200],sum = 0;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if(sum == x) {
    cout << n << endl;
    return 0;
  }
  else if(sum < x) {
    cout << n-1 << endl;
    return 0;
  }

  sort(a,a+n);
  
  for(int i = 0; i < n; i++) {
    if(x >= a[i]) x -= a[i];
    else {
      cout << i << endl;
      break;
    }
  }
}
