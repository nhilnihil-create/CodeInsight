#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  ll x,y;
  cin >> x >> y;
  if (x%y == 0) cout << -1 << endl;
  else cout << x << endl;
}