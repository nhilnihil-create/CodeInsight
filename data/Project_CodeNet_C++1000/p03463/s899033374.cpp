#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << ((b - a) % 2 == 0 ? "Alice" : "Borys") << endl;
  return 0;
} 