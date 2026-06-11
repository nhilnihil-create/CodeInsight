#include<bits/stdc++.h>

#define rep(i, n) for(int i = 1; i <= (n); ++i)

using namespace std;

using ll = long long;

int main() {
  int n, k; cin >> n >> k;

  ll ans = pow(n/k, 3);
  if(!(k%2)) ans += pow((n+(k/2))/k, 3);
  cout << ans << endl;
}