#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,k;
  cin >> n >> k;
  n++;
  if(n/2 >= k) cout << "YES" << endl;
  else cout << "NO" << endl;
}