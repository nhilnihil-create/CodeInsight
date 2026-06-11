#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  if(A*C < B) cout << C;
  else cout << B/A;
}

