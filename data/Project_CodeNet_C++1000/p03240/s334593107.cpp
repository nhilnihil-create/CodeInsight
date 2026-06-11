#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,x[200],y[200],h[200];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> h[i];

  int H;
  for(int cx = 0; cx <= 100; cx++) {
    for(int cy = 0; cy <= 100; cy++) {
      for(int i = 0; i < n; i++) {
        if(h[i] != 0) {
          H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
          break;
        }
      }
      for(int i = 0; i < n; i++) {
        if(h[i] != max(H-abs(x[i]-cx)-abs(y[i]-cy), 0))
            goto Loop;
      }
      cout << cx << " " << cy << " " << H << endl;
      goto Exit;
      Loop: ;
    }
  }

  Exit: return 0;
}