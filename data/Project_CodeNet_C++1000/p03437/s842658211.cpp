#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll X, Y, ans;
  
  cin >> X >> Y;
  
  if (X % Y == 0) {
    cout << -1 << endl;
    
    return 0;
  }
  
  cout << X * (Y - 1) << endl;
  
  return 0;
}