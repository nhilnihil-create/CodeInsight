#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int res = a-b+1;
  if(res%2==0) puts("Borys");
  else puts("Alice");
  return 0;
}
