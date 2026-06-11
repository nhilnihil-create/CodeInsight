#ifdef ConanYu
#include "local.hpp"
#else
#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

void Main() {
  int m, k; cin >> m >> k;
  if(m == 0) {
    if(k == 0) {
      cout << "0 0\n";
    } else {
      cout << "-1\n";
    }
  } else if(m == 1) {
    if(k == 0) {
      cout << "0 0 1 1\n";
    } else {
      cout << "-1\n";
    }
  } else {
    if(k < (1 << m)) {
      if(k == 0) {
        for(int i = 0; i < (1 << m); i++) {
          cout << i << " " << i << " \n"[i + 1 == (1 << m)];
        }
      } else {
        cout << "0 " << k << " 0 ";
        for(int i = 1; i < (1 << m); i++) {
          if(i == k) continue;
          cout << i << " ";
        }
        cout << k << " ";
        for(int i = (1 << m) - 1; i >= 1; i--) {
          if(i == k) continue;
          cout << i << " \n"[i == 1];
        }
      }
    } else {
      cout << "-1\n";
    }
  }
}