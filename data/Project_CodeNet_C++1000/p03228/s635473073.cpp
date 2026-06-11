#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  for (int i = 0; i < k; i++){
    if (i % 2 == 0) {
    if (a & 1) a--;
    b += a / 2;
    a /= 2;
    } else {
    if (b & 1) b--;
    a += b / 2;
    b /= 2;
    }
  }
  cout << a << " " << b << endl;
  return 0;
} 