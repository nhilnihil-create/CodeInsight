#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  long double N, M;
  cin >> N >> M;
  long double x = (100*(N-M)+1900*M);
  int temp = M;
  while(temp--) {
    x *= 2.0l;
  }
  cout << (int) x << endl;
  return 0;
}
