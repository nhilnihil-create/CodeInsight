#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b;
  cin >> a >> b;

  bool ans = false;
  for (int i = 1; i <= 3; i++){
    if (a * b * i % 2 == 1) ans = true;
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
