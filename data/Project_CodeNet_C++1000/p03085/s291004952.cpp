#include <bits/stdc++.h>
using namespace std;

char b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> b;
  if(b == 'A'){
    cout << 'T' <<endl;
  }
  if(b == 'T'){
    cout << 'A' <<endl;
  }
  if(b == 'C'){
    cout << 'G' <<endl;
  }
  if(b == 'G'){
    cout << 'C' <<endl;
  }
}