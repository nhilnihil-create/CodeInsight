#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int a,b;
  cin >> a>>b;
  int x = max(a,b);
  if(x > 8)cout << ":(" << endl;
  else cout << "Yay!" << endl;
}
  
