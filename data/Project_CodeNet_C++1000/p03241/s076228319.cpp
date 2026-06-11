#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int n;
  ll m;
  cin >> n >> m;

  ll d = m / n;
  for (ll i = d;;d--){
    if ((d + (m - d * n)) % d == 0){
      cout << d << endl;
      return 0;
    }
  }  
  return 0;
}
