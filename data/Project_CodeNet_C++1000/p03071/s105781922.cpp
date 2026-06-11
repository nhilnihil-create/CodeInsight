#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int a, b;
  cin >> a >> b;
  cout << max(a+b,max(2*a-1,2*b-1)) << endl;
  return 0;
}