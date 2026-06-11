#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
int main() {
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];
  sort(ALL(v));
  cout << v[2] * 10 + v[1] + v[0];
  return 0;
}
