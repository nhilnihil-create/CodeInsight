#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;
int si[8] = {-1,0,1,-1,1,-1,0,1};
int sj[8] = {-1,-1,-1,0,0,1,1,1};

int main() {
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  int x = 0, y = 0, z = 0;
  rep(i,n){
    int p;
    cin >> p;
    if (p <= a) x++;
    if (a+1 <= p && p <= b) y++;
    if (b+1 <= p) z++;
  }
  cout << min(x, min(y,z)) << endl;
  return 0;
}
