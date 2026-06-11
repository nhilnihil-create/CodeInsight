#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
  int a, b, x;
  cin >> a >> b >> x;
  int xa = x-a;
  if(xa<0) cout << "NO" << endl;
  else if(xa<=b) cout << "YES" << endl;
  else cout << "NO" << endl;
}