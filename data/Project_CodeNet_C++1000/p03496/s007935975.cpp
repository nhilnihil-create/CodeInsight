#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a[51];

  cin >> n;
  int amax = 0, amin = 0, x, imax, imin;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[i] = x;
    if (x > amax) {
      amax = x;
      imax = i;
    }
    if (x < amin) {
      amin = x;
      imin = i;
    }
  }

  if (amax == 0 && amin == 0) {
    cout << 0 << endl;
    return 0;
  }

  int cnt = 0;
  if (amax >= abs(amin)) {
    for (int i = 1; i <= n; i++) {
      if (i != imax) {
        //a[i] += amax;
        //cout << imax << " " << i << endl;
        cnt++;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (i != imin) {
        //a[i] += amin;
        //cout << imin << " " << i << endl;
        cnt++;
      }
    }
  }

  if (amax >= abs(amin)) {
    for (int i = 2; i <= n; i++) {
      //a[i] += a[i-1];
      //cout << i-1 << " " << i << endl;
      cnt++;
    }
  } else {
    for (int i = n-1; i >= 1; i--) {
      //a[i] -= a[i+1];
      //cout << i << " " << i+1 << endl;
      cnt++;
    }
  }

  cout << cnt << endl;
  if (amax >= abs(amin)) {
    for (int i = 1; i <= n; i++) {
      if (i != imax) {
        cout << imax << " " << i << endl;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (i != imin) {
        cout << imin << " " << i << endl;
      }
    }
  }

  if (amax >= abs(amin)) {
    for (int i = 2; i <= n; i++) {
      cout << i-1 << " " << i << endl;
    }
  } else {
    for (int i = n-1; i >= 1; i--) {
      cout << i+1 << " " << i << endl;
    }
  }
  
  return 0;

}
