#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  int x = n / 111;
  int rem = n % 111;
  if(rem != 0) x += 1;
  
  int ans = x * 111;
  
  cout << ans << endl;
}