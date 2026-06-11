#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  int X = 111;
  rep(i, 10) {
    if(N <= X) {
      break;
    }
    X += 111;
  }
  cout << X << endl;
}