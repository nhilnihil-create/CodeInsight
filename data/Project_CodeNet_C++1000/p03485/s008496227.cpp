#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int a,b;
  cin >> a >> b;
  int x = (a+b)/2;
  if(a%2==0&&b%2==0 || a%2==1&&b%2==1) cout << x << endl;
  else cout << x+1 << endl;
}