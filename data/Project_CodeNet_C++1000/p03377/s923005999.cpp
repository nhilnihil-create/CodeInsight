#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int a,b,x;
  cin >> a >> b >> x;
  if(x-a <= b && x-a>=0)cout << "YES" << endl;
  else cout << "NO" << endl;
}