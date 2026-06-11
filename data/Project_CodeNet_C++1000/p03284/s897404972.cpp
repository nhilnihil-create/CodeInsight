#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main(){
  int n, k;
  cin >> n >> k;
  int d = n % k;
  if (d == 0) cout << 0 << endl;
  else cout << 1 << endl;
}
