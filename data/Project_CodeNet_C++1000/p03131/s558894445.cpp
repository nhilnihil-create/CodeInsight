#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll k, a, b;
  cin >> k >> a >> b;

  if(b-a<=2||k<a+1) cout << k+1 << endl;
  else cout << a+(k-a+1)/2*(b-a)+(k-a+1)%2 << endl;
}
