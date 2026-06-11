#include <bits/stdc++.h>

using namespace std;


#define MAXN 1000000
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(a, b) << " " << max(0, n-(n-a)-(n-b)) << endl;
  return 0;
}