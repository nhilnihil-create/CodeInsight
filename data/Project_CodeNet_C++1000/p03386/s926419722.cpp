#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int a,b,k; cin >> a >> b >> k;

  for (int i = a; i <= min(b, a+k-1); i++) printf("%d\n", i);
  for (int i = max(b-k+1, a+k); i <= b; i++) printf("%d\n", i);
}