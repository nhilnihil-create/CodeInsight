
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
int main() {
  int A, B;
  cin >> A >> B;
  int ans;
  if(A >= 13) ans = B;
  else if(A <= 5) ans = 0;
  else ans = B /2;
  cout << ans << endl;
}