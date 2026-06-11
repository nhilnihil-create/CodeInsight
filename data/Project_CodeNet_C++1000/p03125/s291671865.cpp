#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll a, b; cin >> a >> b;
  ll res = b%a==0 ? a+b : b-a;
  cout << res << endl;
  return 0;
}