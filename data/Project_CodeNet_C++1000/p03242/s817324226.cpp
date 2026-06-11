#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string n;
  cin >> n;
  
  rep(i, 3) {
    if(n[i] == '1') cout << 9;
    else cout << 1;
  }
  
  cout << endl;
  
  
  return 0;
}
