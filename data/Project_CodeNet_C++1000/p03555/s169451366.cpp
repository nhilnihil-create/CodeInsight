#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  char c11, c12, c13, c21, c22, c23;
  cin >> c11 >> c12 >> c13 >> c21 >> c22 >> c23;

  if(c11==c23 && c12==c22 && c13==c21){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}