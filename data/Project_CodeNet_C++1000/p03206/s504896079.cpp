#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int d;
  cin >> d;
  cout << "Christmas ";
  d = 25 - d;
  rep(i,d)
    cout << "Eve ";
}
