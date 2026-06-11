#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
int main() {
  int n, m, X, Y, z;

  cin >> n >> m >> X >> Y;
  rep(i,n)
  {
    cin >> z;
    X = max(X, z);
  }
  rep(i,m)
  {
    cin >> z;
    Y = min(Y, z);
  }
  if (X >= Y) {
    cout << "War";
  } else {
    cout << "No War";
  }
  return 0;
}
